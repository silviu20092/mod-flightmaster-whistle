# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

# Flightmaster Whistle module for AzerothCore

## Overview

Adds the possibility for players to teleport to nearest flight master in their area. This is an item that was added on Retail WoW starting with Legion expansion. This module aims to simulate that functionality.


## How to install

1. Clone this repository to your AzerothCore repo modules folder. You should now have mod-flightmaster-whistle there.
2. Re-run cmake to generate the solution.
3. Re-build your project.
4. You should have mod_flightmaster_whistle.conf.dist copied in configs/modules after building, copy this to configs/modules in your server's base directory.
5. Start the server, .sql files should automatically be imported in DB, if not, apply them manually.

## How to use

Use command **.fmw** or use the item (**.additem 70000**). Check the **mod_flightmaster_whistle.conf.dist** config for the mod options.

## Credits
- silviu20092