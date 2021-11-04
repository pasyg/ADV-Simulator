# Work in progress
## ADV-Simulator

A battle simulator for the third generation of the pokemon games.

## important customizable functions
### src/main.cpp:
  structure of the game, team import.
### src/team/team.cpp // decide_move()
  implementation of decision processes for battles
### src/tools/import.cpp
  function to customize importable team formats, currently only supports the [packed pokemon showdown format](https://github.com/smogon/pokemon-showdown/blob/master/sim/TEAMS.md)
  most values have to be set for later initialization
  
Structural Inspiration: [Technical Machine](https://github.com/davidstone/technical-machine)
