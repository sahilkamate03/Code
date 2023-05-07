#!/bin/bash
ROOT_FOLDER="/run/user/1000/gvfs/"
cd $ROOT_FOLDER
ANDROID_FOLDER=$ROOT_FOLDER"$(ls)/Internal shared storage/"
DCIM=$ANDROID_FOLDER"DCIM/"
WHATSAPP=$ANDROID_FOLDER"Android/media/com.whatsapp/WhatsApp/Media/WhatsApp Images/"
PC_FOLDER="$HOME/test"
FOLDER_NAME=$PC_FOLDER"/$(date "+%T")"
mkdir "$FOLDER_NAME"
echo "Task1...Started..."
COPY_PATH="$FOLDER_NAME/DCIM"
mkdir "$COPY_PATH"
find "$DCIM" -type f \( -iname "*.jpg" -o -iname "*.jpeg" -o -iname "*.png" \) -exec cp {} "$COPY_PATH" \;
echo "Completed..."
echo "Task2...Started..."
COPY_PATH="$FOLDER_NAME/Whatsapp"
cp -r "$WHATSAPP" "$COPY_PATH"
echo "Completed..."
echo "Task3...Started..."
COPY_PATH="$FOLDER_NAME/Video"
mkdir "$COPY_PATH"
find "$DCIM" -type f \( -iname "*.mp4" -o -iname "*.avi" -o -iname "*.mkv" \) -exec cp {} "$COPY_PATH" \;
echo "Completed..."
