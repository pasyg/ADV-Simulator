# Work in progress
## ADV-Simulator

A battle simulator for the third generation of the pokemon games.

## important customizable functions
### src/constants
  most importantly turn cap per game
### src/main.cpp:
  structure of the game, team import.
### src/battle/decide_move // decide_move():
  implementation of decision processes for battles
### src/tools/import.cpp // import_team():
  function to customize importable team formats, currently only supports the [packed pokemon showdown format](https://github.com/smogon/pokemon-showdown/blob/master/sim/TEAMS.md)
  most values have to be set for later initialization
  
Structural Inspiration: [Technical Machine](https://github.com/davidstone/technical-machine)

Sources:
End of turn mechanics:
https://pastebin.com/HbcXtCN7

Damage calculation:
https://bulbapedia.bulbagarden.net/wiki/Damage

Hidden Power calculation:
https://bulbapedia.bulbagarden.net/wiki/Hidden_Power_(move)/Calculation#Damage
