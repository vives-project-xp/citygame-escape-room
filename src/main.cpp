#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "Board.h"
#include "settings.h"
#include "Packet.h"
#include "Logger.h"
#include "StringReader.h"
#include "GameHandler.h"

using namespace SimpleLoRaWAN;

Serial pc(USBTX, USBRX);
Thread gps_thread;
Thread send_thread;
DigitalOut fix_led(LED4);
Logger logger(&pc);

Node* node;
Board* board;
GameHandler* gameHandler;

static const float GPS_UPDATE_TIME = 2.0;
static const float LORAWAN_INTERVAL = 10.0;

char buffer[2048];

void show_gps_info()
{
    while(true){
        logger.gps(board->gps);
        logger.game(gameHandler->game);
        Thread::wait(GPS_UPDATE_TIME*1000);
    }
}

void send_info()
{
    while(true){
        if(board->gps->fix){
            pc.printf("Sending packet:");
            uint8_t* packet = Packet::build(board->gps, gameHandler->game);
            logger.packet(packet);
            node->send(packet, 9);
        }
        Thread::wait(LORAWAN_INTERVAL*1000);
    }
}

void init()
{
    pc.baud(115200);
    pc.printf("\n\nInitializing Vives CityGame\n");

    node = new ABP::Node(devAddr, nwksKey, appKey);
    node->disableLinkCheck();
    node->setSpreadFactor(DR_SF7);

    board = new Board();

    ConfigReader * reader = new StringReader("{\"name\":\"LocationGame\",\"box_description\":\"Go to locations.\",\"full_description\":\"Whilst bringing the rebels to the imperial prison, your stardestroyer got shot. Retrieve the lost communicator parts to contact an extraction team\",\"length\":3000,\"time\":120,\"missions\":[{\"id\":1,\"name\":\"GotoLocation\",\"description\":\"The first part is at the entrance of Kinepolis\",\"locations\":[{\"lat\":51.223142,\"long\":2.896536,\"radius\":20.3}]},{\"id\":2,\"name\":\"GotoLocation\",\"description\":\"The next one is at the Spar\",\"locations\":[{\"lat\":51.222359,\"long\":2.892109,\"radius\":15.5}]}]}");
    //ConfigReader * reader = new StringReader("{\"name\":\"LocationGame\",\"box_description\":\"Go to locations.\",\"full_description\":\"Whilst bringing the rebels to the imperial prison, your stardestroyer got shot. Retrieve the lost communicator parts to contact an extraction team\",\"length\":3000,\"time\":120,\"missions\":[{\"id\":1,\"name\":\"GotoLocation\",\"description\":\"The first part is at the entrance of Kinepolis\",\"locations\":[{\"lat\":51.223142,\"long\":2.896536,\"radius\":900.0}]},{\"id\":2,\"name\":\"GotoLocation\",\"description\":\"The next one is at the Spar\",\"locations\":[{\"lat\":51.222359,\"long\":2.892109,\"radius\":900.0}]}]}");
    reader->read(buffer, sizeof(buffer));
    pc.printf("\n Content: --------------------------- \n %s \n ------------------------------------------- \n", buffer);

    gameHandler = new GameHandler(buffer, board);

    gps_thread.start(show_gps_info);
    send_thread.start(send_info);
}

int main(void)
{
    init();
    wait(1.0);

    while(true){
        node->process();
        board->gps->run();
        fix_led = !board->gps->fix;
        if(board->gps->fix) gameHandler->run();
    }
}
