# CTerm

A small application that can be used to change your terminal output colors

This application is configured to run on normal Bash terminal

# Build instructions

The `Makefile` is provided, simply call `make cterm` or `make` in the current directory. 

The `Makefile` is configured to work on Bash by default. 

If you are using zsh (default shell on Mac), please compile with `make cterm_zsh`.

After compiling, you can copy the executables `cterm` and `ct` into `/usr/bin` or `/bin` or any other location in your PATH for easy execution. 

# Usage

Run `cterm --help` or `cterm -h` to obtain the manual. 

The program is also aliased to `ct`, so calling `ct -h` would also work. 

## Example usage

### Changing color of current terminal session

To obtain a change in colors in the current session, you can supply one the following list of osptions to the call `ct <OPTION>`

List of options
  * -b, --black
  * -r, --red
  * -g, --green
  * -y, --yellow
  * -B, --blue
  * -m, --magenta
  * -c, --cyan
  * -w, --white
  * -R, --reset

### Changing color for a specific line of text

To obtain a line with a specific color output, you can type `ct <OPTION> [ARGUMENTS]...`

This will output the following arguments in the specified color. 

Example, `ct -r This sentence is now red.` will output a red line.

# Cautions

This program only takes up to **16** arguments and each argument can only be up to **128** characters long. 