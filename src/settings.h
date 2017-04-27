
// LoRaWAN TTN Settings

// OTAA Settings
uint8_t appEui[8]  = { 0x70, 0xB3, 0xD5, 0x7E, 0xF0, 0x00, 0x39, 0x78 }; // MSBF
uint8_t devEui[8]  = { 0x00, 0x28, 0x27, 0x71, 0xDE, 0xE0, 0x80, 0x80 }; // MSBF

// ABP Settings
uint32_t devAddr    = 0x26011650;
uint8_t nwksKey[16] = { 0x31, 0x5F, 0x66, 0x06, 0xB0, 0x3C, 0xBB, 0x45, 0x18, 0x89, 0xB3, 0xE4, 0xB0, 0xB9, 0x36, 0x49 }; // LSBF
uint8_t appKey[16]  = { 0x4C, 0x43, 0xCC, 0x8B, 0x20, 0x34, 0x28, 0xE3, 0xFC, 0xE6, 0x5D, 0xC0, 0xAD, 0x2D, 0xBB, 0x25 }; // LSBF

