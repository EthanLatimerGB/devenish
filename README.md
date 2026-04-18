# Devenish 

> A Pebble Integration with the [xDrip+ application](https://github.com/NightscoutFoundation/xDrip).

## Developer Instructions

1. Install the [Pebble SDK](https://developer.repebble.com/sdk/) to get started.
2. Run `git submodule init --recursive` to install some helper functions.
3. Run `pebble build` to build the application.
4. To run the emulator, make sure to have the SDK installed and run 
`pebble install --emulator <aplite|basalt|chalk|diorite|emery|gabbro>` 

> INFO: 
> If you use clangd like I do. You'll want the `compile_commands.json` file
> so that you can get LSP support of pebble-sdk.
> You SHOULD do step 2 above, then in the root of this project, run 
> `./pebble-scripts/create_compile_commands.sh > compile_commands.json`.
>
> You may see an error like `In included file: redefinition of 'tm'`, but don't 
> worry about that. It's still fully functional.


