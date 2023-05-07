#!/bin/bash
function handle_error {
    echo "An error occurred on line $1. Exiting."
    exit 1
}

trap 'handle_error $LINENO' ERR

cd "$HOME/code"
git add .
git commit -m "$(date +%F) -ab"
git push origin main
echo "Backup Done..."
