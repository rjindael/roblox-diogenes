# roblox-diogenes
Encypt files in the Roblox compatible diogenes format, or decrypt them

## Usage
Open up in Visual Studio and click Build, or download the latest release at the [Releases tab](https://github.com/lighterlightbulb/RobloxDiogenes/releases).

Open it up, input the file name (or file path) to the diogenes file. It will write a `diogenes_output.fnt` to the current working directory of where you have stored the executable.

You can also run roblox-diogenes through the command line, like so:

```
roblox-diogenes [ ARGUMENTS ... ]

	-f, --file   <input_file_path>  The input diogenes file path, or file name
	-o, --output <output_file_path> The output decrypted / encrypted file path, or file name (default: <working_dir>/diogenes_output.fnt)
```
