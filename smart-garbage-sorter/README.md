# Smart Garbage Sorter

Smart Garbage Sorter is a university group project focused on automated waste sorting.

## How it works (planned)
- An ESP32 captures an image of a waste item.
- The image is sent to an Android phone.
- An AI model running locally on the Android phone classifies the item as **trash**, **recycling**, **compost**, or **bottle**.
- Android sends the classification result back to the ESP32.
- The ESP32 controls a servo mechanism to sort the item.
- Sensors monitor how full each bin is and the Android app sends notifications when a bin is full.

## Folder overview
- `android-app/`: Android mobile app and on-device ML integration assets.
- `esp32-firmware/`: ESP32 embedded firmware source, headers, libraries, and tests.
- `pcb/`: Hardware design outputs including KiCad files, BOMs, gerbers, and exports.
- `docs/`: Project documentation such as architecture, requirements, backlog, sprint notes, testing, and ethics.
- `presentations/`: Slide decks and presentation material.
- `images/`: Project images and visual assets.
