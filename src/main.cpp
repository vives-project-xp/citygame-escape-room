#include "mbed.h"
#include "Board.h"
#include "StringReader.h"
#include "GameHandler.h"
#include "mbed_trace.h"

#define TRACE_GROUP "MAIN"

BufferedSerial pc(USBTX, USBRX, 115200);
Thread send_thread;
Thread * setupGameThread;

Board* board;
GameHandler* gameHandler;

char buffer[2048];

void setup_game_handler(void) {
  //ConfigReader * reader = new StringReader("{\"name\":\"LocationGame\",\"box_description\":\"Go to locations.\",\"full_description\":\"Whilst bringing the rebels to the imperial prison, your stardestroyer got shot. Retrieve the lost communicator parts to contact an extraction team\",\"length\":3000,\"time\":120,\"missions\":[{\"id\":1,\"name\":\"GotoLocation\",\"description\":\"The first part is at the entrance of Kinepolis\",\"typeid\":10,\"locations\":[{\"lat\":51.223142,\"long\":2.896536,\"radius\":12.5}]},{\"id\":2,\"name\":\"GotoLocation\",\"description\":\"The next one is at the Spar\",\"typeid\":10,\"locations\":[{\"lat\":51.222359,\"long\":2.892109,\"radius\":12.5}]},{\"id\":3,\"name\":\"FindAKey\",\"description\":\"There is a key on the light pole\",\"typeid\":20}]}");
  ConfigReader * reader = new StringReader("{\"name\":\"LocationGame\",\"box_description\":\"Go to locations.\",\"full_description\":\"Whilst bringing the rebels to the imperial prison, your stardestroyer got shot. Retrieve the lost communicator parts to contact an extraction team\",\"length\":3000,\"time\":120,\"missions\":[{\"id\":3,\"name\":\"FindAKey\",\"description\":\"There is a key on the light pole\",\"typeid\":20},{\"id\":1,\"name\":\"GotoLocation\",\"description\":\"The first part is at the entrance of Kinepolis\",\"typeid\":10,\"locations\":[{\"lat\":51.223142,\"long\":2.896536,\"radius\":20.3}]},{\"id\":2,\"name\":\"GotoLocation\",\"description\":\"The next one is at the Spar\",\"typeid\":10,\"locations\":[{\"lat\":51.222359,\"long\":2.892109,\"radius\":15.5}]}]}");

  reader->read(buffer, sizeof(buffer));
  printf("\n Content: --------------------------- \n %s \n ------------------------------------------- \n", buffer);

  gameHandler = new GameHandler(buffer, board);
}

void createSetupThread(void) {
  setupGameThread = new Thread(osPriorityNormal, 1024 *20);

  setupGameThread->start(setup_game_handler);
  setupGameThread->join();   // Wait for completion

  delete setupGameThread;
}

void init()
{
    mbed_trace_init();
    tr_info("Initializing Vives CityGame");

    board = new Board();

    createSetupThread();
}

int main(void)
{
    init();
    ThisThread::sleep_for(1s);

    while(true){
        gameHandler->run();
    }
}
