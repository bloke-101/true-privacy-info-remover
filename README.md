# True-Privacy-Info-Remover

**True-Privacy-Info-Remover** is a CLI tool to erase data by overwriting
a file several times.

The tool allows a user to apply **the Bruce Schneier's algorithm** or
overwrite a file with the provided byte values.

**The Bruce Schneier's algorithm** wipes a file **seven times**. The
first pass overwrites the file with the bit pattern **"00"**, the
second with **"11"**, and the next five with a randomly generated bit
pattern.

If you offer byte values to wipe a file, it will be overwritten as
many times as the byte values have been provided.

## How to build the tool

``chmod +x build.sh && ./build.sh``

## How to run the tool

### Wipe a file with the Bruce Schneier's algorithm

``bin/true_privacy_info_remover file_to_overwrite.txt``

### Wipe a file with the provided byte values

``bin/true_privacy_info_remover file_to_overwrite.txt byte_values.txt``
