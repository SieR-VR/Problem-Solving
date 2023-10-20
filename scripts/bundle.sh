bundled=`node ./scripts/js/bundle.js $1`

echo "$bundled"
echo "$bundled" | xclip -selection clipboard

echo "Copied to clipboard"
