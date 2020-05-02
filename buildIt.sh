rm -rf build/assets
cp -r assets/ build/
echo "Directory Copied"
cd build
rm CMakeCache.txt
cmake ..
cmake --build . --config Release
./MyApp