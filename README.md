# Smart Garbage Sorter

Smart Garbage Sorter is a university group project that automates waste sorting.

## Workflow
- An ESP32 captures an image of a waste item.
- The image is sent to an Android phone.
- An AI model running locally on Android classifies the item as **trash**, **recycling**, **compost**, or **bottle**.
- Android sends the classification result back to the ESP32.
- The ESP32 controls a servo mechanism to sort the item.
- Sensors monitor bin fullness, and the Android app sends notifications when a bin is full.

## Repository structure
- `android-app/`: Android application and on-device ML assets.
- `esp32-firmware/`: ESP32 firmware and embedded control code.
- `pcb/`: PCB design-related materials and manufacturing exports.
- `docs/`: Project documentation (architecture, requirements, process, testing, ethics).
- `presentations/`: Slide decks and presentation materials.
- `images/`: Project images and visual assets.
