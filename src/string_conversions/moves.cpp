#include "Moves.hpp"

std::string_view to_string(Move const move){
    switch (move) {
		case Move::Pass: return "Pass";
		case Move::Switch0: return "Switch0";
		case Move::Switch1: return "Switch1";
		case Move::Switch2: return "Switch2";
		case Move::Switch3: return "Switch3";
		case Move::Switch4: return "Switch4";
		case Move::Switch5: return "Switch5";
		case Move::Hit_Self: return  "Hit self in confusion";

		case Move::Pound: return "Pound";
		case Move::Karate_Chop: return  "Karate Chop";
		case Move::Double_Slap: return  "Double Slap";
		case Move::Comet_Punch: return  "Comet Punch";
		case Move::Mega_Punch: return "Mega Punch";
		case Move::Pay_Day: return "Pay Day";
		case Move::Fire_Punch: return  "Fire Punch";
		case Move::Ice_Punch: return  "Ice Punch";
		case Move::Thunder_Punch: return "Thunder Punch";
		case Move::Scratch: return "Scratch";
		case Move::Vice_Grip: return "Vice Grip";
		case Move::Guillotine: return  "Guillotine";
		case Move::Razor_Wind: return "Razor Wind";
		case Move::Swords_Dance: return "Swords Dance";
		case Move::Cut: return  "Cut";
		case Move::Gust: return  "Gust";
		case Move::Wing_Attack: return "Wing Attack";
		case Move::Whirlwind: return "Whirlwind";
		case Move::Fly: return  "Fly";
		case Move::Bind: return  "Bind";
		case Move::Slam: return "Slam";
		case Move::Vine_Whip: return "Vine Whip";
		case Move::Stomp: return "Stomp";
		case Move::Double_Kick: return  "Double Kick";
		case Move::Mega_Kick: return "Mega Kick";
		case Move::Jump_Kick: return  "Jump Kick";
		case Move::Rolling_Kick: return "Rolling Kick";
		case Move::Sand_Attack: return "Sand Attack";
		case Move::Headbutt: return  "Headbutt";
		case Move::Horn_Attack: return  "Horn Attack";
		case Move::Fury_Attack: return  "Fury Attack";
		case Move::Horn_Drill: return  "Horn Drill";
		case Move::Tackle: return "Tackle";
		case Move::Body_Slam: return  "Body Slam";
		case Move::Wrap: return "Wrap";
		case Move::Take_Down: return "Take Down";
		case Move::Thrash: return "Thrash";
		case Move::Double_Edge: return  "Double-Edge";
		case Move::Tail_Whip: return "Tail Whip";
		case Move::Poison_Sting: return "Poison Sting";
		case Move::Twineedle: return "Twineedle";
		case Move::Pin_Missile: return "Pin Missile";
		case Move::Leer: return "Leer";
		case Move::Bite: return  "Bite";
		case Move::Growl: return  "Growl";
		case Move::Roar: return "Roar";
		case Move::Sing: return "Sing";
		case Move::Supersonic: return "Supersonic";
		case Move::Sonic_Boom: return "Sonic Boom";
		case Move::Disable: return  "Disable";
		case Move::Acid: return  "Acid";
		case Move::Ember: return  "Ember";
		case Move::Flamethrower: return  "Flamethrower";
		case Move::Mist: return "Mist";
		case Move::Water_Gun: return "Water Gun";
		case Move::Hydro_Pump: return  "Hydro Pump";
		case Move::Surf: return "Surf";
		case Move::Ice_Beam: return  "Ice Beam";
		case Move::Blizzard: return  "Blizzard";
		case Move::Psybeam: return "Psybeam";
		case Move::Bubble_Beam: return  "Bubble Beam";
		case Move::Aurora_Beam: return  "Aurora Beam";
		case Move::Hyper_Beam: return  "Hyper Beam";
		case Move::Peck: return "Peck";
		case Move::Drill_Peck: return  "Drill Peck";
		case Move::Submission: return "Submission";
		case Move::Low_Kick: return "Low Kick";
		case Move::Counter: return  "Counter";
		case Move::Seismic_Toss: return "Seismic Toss";
		case Move::Strength: return "Strength";
		case Move::Absorb: return  "Absorb";
		case Move::Mega_Drain: return "Mega Drain";
		case Move::Leech_Seed: return "Leech Seed";
		case Move::Growth: return  "Growth";
		case Move::Razor_Leaf: return "Razor Leaf";
		case Move::Solar_Beam: return "Solar Beam";
		case Move::Poison_Powder: return "Poison Powder";
		case Move::Stun_Spore: return "Stun Spore";
		case Move::Sleep_Powder: return "Sleep Powder";
		case Move::Petal_Dance: return "Petal Dance";
		case Move::String_Shot: return "String Shot";
		case Move::Dragon_Rage: return  "Dragon Rage";
		case Move::Fire_Spin: return  "Fire Spin";
		case Move::Thunder_Shock: return "Thunder Shock";
		case Move::Thunderbolt: return "Thunderbolt";
		case Move::Thunder_Wave: return "Thunder Wave";
		case Move::Thunder: return "Thunder";
		case Move::Rock_Throw: return "Rock Throw";
		case Move::Earthquake: return  "Earthquake";
		case Move::Fissure: return  "Fissure";
		case Move::Dig: return  "Dig";
		case Move::Toxic: return "Toxic";
		case Move::Confusion: return  "Confusion";
		case Move::Psychic: return "Psychic";
		case Move::Hypnosis: return  "Hypnosis";
		case Move::Meditate: return "Meditate";
		case Move::Agility: return  "Agility";
		case Move::Quick_Attack: return "Quick Attack";
		case Move::Rage: return "Rage";
		case Move::Teleport: return "Teleport";
		case Move::Night_Shade: return "Night Shade";
		case Move::Mimic: return "Mimic";
		case Move::Screech: return "Screech";
		case Move::Double_Team: return  "Double Team";
		case Move::Recover: return "Recover";
		case Move::Harden: return  "Harden";
		case Move::Minimize: return "Minimize";
		case Move::Smokescreen: return "Smokescreen";
		case Move::Confuse_Ray: return  "Confuse Ray";
		case Move::Withdraw: return "Withdraw";
		case Move::Defense_Curl: return  "Defense Curl";
		case Move::Barrier: return  "Barrier";
		case Move::Light_Screen: return "Light Screen";
		case Move::Haze: return  "Haze";
		case Move::Reflect: return "Reflect";
		case Move::Focus_Energy: return  "Focus Energy";
		case Move::Bide: return  "Bide";
		case Move::Metronome: return "Metronome";
		case Move::Mirror_Move: return "Mirror Move";
		case Move::Self_Destruct: return "Self-Destruct";
		case Move::Egg_Bomb: return  "Egg Bomb";
		case Move::Lick: return "Lick";
		case Move::Smog: return "Smog";
		case Move::Sludge: return "Sludge";
		case Move::Bone_Club: return  "Bone Club";
		case Move::Fire_Blast: return  "Fire Blast";
		case Move::Waterfall: return "Waterfall";
		case Move::Clamp: return  "Clamp";
		case Move::Swift: return "Swift";
		case Move::Skull_Bash: return "Skull Bash";
		case Move::Spike_Cannon: return "Spike Cannon";
		case Move::Constrict: return  "Constrict";
		case Move::Amnesia: return  "Amnesia";
		case Move::Kinesis: return  "Kinesis";
		case Move::Soft_Boiled: return "Soft-Boiled";
		case Move::High_Jump_Kick: return  "High Jump Kick";
		case Move::Glare: return  "Glare";
		case Move::Dream_Eater: return  "Dream Eater";
		case Move::Poison_Gas: return "Poison Gas";
		case Move::Barrage: return  "Barrage";
		case Move::Leech_Life: return "Leech Life";
		case Move::Lovely_Kiss: return "Lovely Kiss";
		case Move::Sky_Attack: return "Sky Attack";
		case Move::Transform: return "Transform";
		case Move::Bubble: return  "Bubble";
		case Move::Dizzy_Punch: return  "Dizzy Punch";
		case Move::Spore: return "Spore";
		case Move::Flash: return  "Flash";
		case Move::Psywave: return "Psywave";
		case Move::Splash: return "Splash";
		case Move::Acid_Armor: return  "Acid Armor";
		case Move::Crabhammer: return  "Crabhammer";
		case Move::Explosion: return  "Explosion";
		case Move::Fury_Swipes: return  "Fury Swipes";
		case Move::Bonemerang: return  "Bonemerang";
		case Move::Rest: return "Rest";
		case Move::Rock_Slide: return "Rock Slide";
		case Move::Hyper_Fang: return  "Hyper Fang";
		case Move::Sharpen: return "Sharpen";
		case Move::Conversion: return  "Conversion";
		case Move::Tri_Attack: return "Tri Attack";
		case Move::Super_Fang: return "Super Fang";
		case Move::Slash: return "Slash";
		case Move::Substitute: return "Substitute";
		case Move::Struggle: return "Struggle";
		case Move::Sketch: return "Sketch";
		case Move::Triple_Kick: return "Triple Kick";
		case Move::Thief: return "Thief";
		case Move::Spider_Web: return "Spider Web";
		case Move::Mind_Reader: return "Mind Reader";
		case Move::Nightmare: return "Nightmare";
		case Move::Flame_Wheel: return  "Flame Wheel";
		case Move::Snore: return "Snore";
		case Move::Curse: return  "Curse";
		case Move::Flail: return  "Flail";
		case Move::Conversion_2: return  "Conversion 2";
		case Move::Aeroblast: return  "Aeroblast";
		case Move::Cotton_Spore: return  "Cotton Spore";
		case Move::Reversal: return "Reversal";
		case Move::Spite: return "Spite";
		case Move::Powder_Snow: return "Powder Snow";
		case Move::Protect: return "Protect";
		case Move::Mach_Punch: return "Mach Punch";
		case Move::Scary_Face: return "Scary Face";
		case Move::Feint_Attack: return  "Feint Attack";
		case Move::Sweet_Kiss: return "Sweet Kiss";
		case Move::Belly_Drum: return  "Belly Drum";
		case Move::Sludge_Bomb: return "Sludge Bomb";
		case Move::Mud_Slap: return "Mud-Slap";
		case Move::Octazooka: return "Octazooka";
		case Move::Spikes: return "Spikes";
		case Move::Zap_Cannon: return "Zap Cannon";
		case Move::Foresight: return  "Foresight";
		case Move::Destiny_Bond: return  "Destiny Bond";
		case Move::Perish_Song: return "Perish Song";
		case Move::Icy_Wind: return  "Icy Wind";
		case Move::Detect: return  "Detect";
		case Move::Bone_Rush: return  "Bone Rush";
		case Move::Lock_On: return "Lock-On";
		case Move::Outrage: return "Outrage";
		case Move::Sandstorm: return "Sandstorm";
		case Move::Giga_Drain: return  "Giga Drain";
		case Move::Endure: return  "Endure";
		case Move::Charm: return  "Charm";
		case Move::Rollout: return "Rollout";
		case Move::False_Swipe: return  "False Swipe";
		case Move::Swagger: return "Swagger";
		case Move::Milk_Drink: return "Milk Drink";
		case Move::Spark: return "Spark";
		case Move::Fury_Cutter: return  "Fury Cutter";
		case Move::Steel_Wing: return "Steel Wing";
		case Move::Mean_Look: return "Mean Look";
		case Move::Attract: return  "Attract";
		case Move::Sleep_Talk: return "Sleep Talk";
		case Move::Heal_Bell: return  "Heal Bell";
		case Move::Return: return "Return";
		case Move::Present: return "Present";
		case Move::Frustration: return  "Frustration";
		case Move::Safeguard: return "Safeguard";
		case Move::Pain_Split: return "Pain Split";
		case Move::Sacred_Fire: return "Sacred Fire";
		case Move::Magnitude: return "Magnitude";
		case Move::Dynamic_Punch: return  "Dynamic Punch";
		case Move::Megahorn: return "Megahorn";
		case Move::Dragon_Breath: return  "Dragon Breath";
		case Move::Baton_Pass: return  "Baton Pass";
		case Move::Encore: return  "Encore";
		case Move::Pursuit: return "Pursuit";
		case Move::Rapid_Spin: return "Rapid Spin";
		case Move::Sweet_Scent: return "Sweet Scent";
		case Move::Iron_Tail: return  "Iron Tail";
		case Move::Metal_Claw: return "Metal Claw";
		case Move::Vital_Throw: return "Vital Throw";
		case Move::Morning_Sun: return "Morning Sun";
		case Move::Synthesis: return "Synthesis";
		case Move::Moonlight: return "Moonlight";
		case Move::Hidden_Power: return  "Hidden Power";
		case Move::Cross_Chop: return  "Cross Chop";
		case Move::Twister: return "Twister";
		case Move::Rain_Dance: return "Rain Dance";
		case Move::Sunny_Day: return "Sunny Day";
		case Move::Crunch: return  "Crunch";
		case Move::Mirror_Coat: return "Mirror Coat";
		case Move::Psych_Up: return "Psych Up";
		case Move::Extreme_Speed: return  "Extreme Speed";
		case Move::Ancient_Power: return  "Ancient Power";
		case Move::Shadow_Ball: return "Shadow Ball";
		case Move::Future_Sight: return  "Future Sight";
		case Move::Rock_Smash: return "Rock Smash";
		case Move::Whirlpool: return "Whirlpool";
		case Move::Beat_Up: return  "Beat Up";
		case Move::Fake_Out: return  "Fake Out";
		case Move::Uproar: return "Uproar";
		case Move::Stockpile: return "Stockpile";
		case Move::Spit_Up: return "Spit Up";
		case Move::Swallow: return "Swallow";
		case Move::Heat_Wave: return  "Heat Wave";
		case Move::Hail: return  "Hail";
		case Move::Torment: return "Torment";
		case Move::Flatter: return  "Flatter";
		case Move::Will_O_Wisp: return "Will-O-Wisp";
		case Move::Memento: return "Memento";
		case Move::Facade: return  "Facade";
		case Move::Focus_Punch: return  "Focus Punch";
		case Move::Smelling_Salts: return "Smelling Salts";
		case Move::Follow_Me: return  "Follow Me";
		case Move::Nature_Power: return "Nature Power";
		case Move::Charge: return  "Charge";
		case Move::Taunt: return "Taunt";
		case Move::Helping_Hand: return  "Helping Hand";
		case Move::Trick: return "Trick";
		case Move::Role_Play: return "Role Play";
		case Move::Wish: return "Wish";
		case Move::Assist: return  "Assist";
		case Move::Ingrain: return  "Ingrain";
		case Move::Superpower: return "Superpower";
		case Move::Magic_Coat: return "Magic Coat";
		case Move::Recycle: return "Recycle";
		case Move::Revenge: return "Revenge";
		case Move::Brick_Break: return  "Brick Break";
		case Move::Yawn: return "Yawn";
		case Move::Knock_Off: return  "Knock Off";
		case Move::Endeavor: return  "Endeavor";
		case Move::Eruption: return  "Eruption";
		case Move::Skill_Swap: return "Skill Swap";
		case Move::Imprison: return  "Imprison";
		case Move::Refresh: return "Refresh";
		case Move::Grudge: return  "Grudge";
		case Move::Snatch: return "Snatch";
		case Move::Secret_Power: return "Secret Power";
		case Move::Dive: return  "Dive";
		case Move::Arm_Thrust: return  "Arm Thrust";
		case Move::Camouflage: return  "Camouflage";
		case Move::Tail_Glow: return "Tail Glow";
		case Move::Luster_Purge: return "Luster Purge";
		case Move::Mist_Ball: return "Mist Ball";
		case Move::Feather_Dance: return  "Feather Dance";
		case Move::Teeter_Dance: return "Teeter Dance";
		case Move::Blaze_Kick: return  "Blaze Kick";
		case Move::Mud_Sport: return "Mud Sport";
		case Move::Ice_Ball: return  "Ice Ball";
		case Move::Needle_Arm: return "Needle Arm";
		case Move::Slack_Off: return "Slack Off";
		case Move::Hyper_Voice: return  "Hyper Voice";
		case Move::Poison_Fang: return "Poison Fang";
		case Move::Crush_Claw: return  "Crush Claw";
		case Move::Blast_Burn: return  "Blast Burn";
		case Move::Hydro_Cannon: return  "Hydro Cannon";
		case Move::Meteor_Mash: return "Meteor Mash";
		case Move::Astonish: return  "Astonish";
		case Move::Weather_Ball: return "Weather Ball";
		case Move::Aromatherapy: return  "Aromatherapy";
		case Move::Fake_Tears: return  "Fake Tears";
		case Move::Air_Cutter: return  "Air Cutter";
		case Move::Overheat: return "Overheat";
		case Move::Odor_Sleuth: return "Odor Sleuth";
		case Move::Rock_Tomb: return "Rock Tomb";
		case Move::Silver_Wind: return "Silver Wind";
		case Move::Metal_Sound: return "Metal Sound";
		case Move::Grass_Whistle: return  "Grass Whistle";
		case Move::Tickle: return "Tickle";
		case Move::Cosmic_Power: return  "Cosmic Power";
		case Move::Water_Spout: return "Water Spout";
		case Move::Signal_Beam: return "Signal Beam";
		case Move::Shadow_Punch: return "Shadow Punch";
		case Move::Extrasensory: return  "Extrasensory";
		case Move::Sky_Uppercut: return "Sky Uppercut";
		case Move::Sand_Tomb: return "Sand Tomb";
		case Move::Sheer_Cold: return "Sheer Cold";
		case Move::Muddy_Water: return "Muddy Water";
		case Move::Bullet_Seed: return  "Bullet Seed";
		case Move::Aerial_Ace: return  "Aerial Ace";
		case Move::Icicle_Spear: return  "Icicle Spear";
		case Move::Iron_Defense: return  "Iron Defense";
		case Move::Block: return  "Block";
		case Move::Howl: return  "Howl";
		case Move::Dragon_Claw: return  "Dragon Claw";
		case Move::Frenzy_Plant: return  "Frenzy Plant";
		case Move::Bulk_Up: return  "Bulk Up";
		case Move::Bounce: return  "Bounce";
		case Move::Mud_Shot: return "Mud Shot";
		case Move::Poison_Tail: return "Poison Tail";
		case Move::Covet: return  "Covet";
		case Move::Volt_Tackle: return "Volt Tackle";
		case Move::Magical_Leaf: return "Magical Leaf";
		case Move::Water_Sport: return "Water Sport";
		case Move::Calm_Mind: return  "Calm Mind";
		case Move::Leaf_Blade: return "Leaf Blade";
		case Move::Dragon_Dance: return  "Dragon Dance";
		case Move::Rock_Blast: return "Rock Blast";
		case Move::Shock_Wave: return "Shock Wave";
		case Move::Water_Pulse: return "Water Pulse";
		case Move::Doom_Desire: return  "Doom Desire";
		case Move::Psycho_Boost: return "Psycho Boost";
        default: return  "ERROR  Move";
    }
}

Move move_from_string(std::string_view const str){

	static std::unordered_map<std::string_view, Move> map{

			{  "Absorb",  Move::Absorb },
			{  "Accelerock",  Move::Accelerock },
			{  "Acid",  Move::Acid },
			{  "Acidarmor",  Move::Acid_Armor },
			{  "Aciddownpour",  Move::Acid_Downpour },
			{  "Acidspray",  Move::Acid_Spray },
			{  "Acrobatics",  Move::Acrobatics },
			{  "Acupressure",  Move::Acupressure },
			{  "Aerialace",  Move::Aerial_Ace },
			{  "Aeroblast",  Move::Aeroblast },
			{  "Afteryou",  Move::After_You },
			{  "Agility",  Move::Agility },
			{  "Aircutter",  Move::Air_Cutter },
			{  "Airslash",  Move::Air_Slash },
			{  "Alloutpummeling",  Move::All_Out_Pummeling },
			{  "Allyswitch",  Move::Ally_Switch },
			{  "Amnesia",  Move::Amnesia },
			{  "Anchorshot",  Move::Anchor_Shot },
			{  "Ancientpower",  Move::Ancient_Power },
			{  "Aquajet",  Move::Aqua_Jet },
			{  "Aquaring",  Move::Aqua_Ring },
			{  "Aquatail",  Move::Aqua_Tail },
			{  "Armthrust",  Move::Arm_Thrust },
			{  "Aromatherapy",  Move::Aromatherapy },
			{  "Aromaticmist",  Move::Aromatic_Mist },
			{  "Assist",  Move::Assist },
			{  "Assurance",  Move::Assurance },
			{  "Astonish",  Move::Astonish },
			{  "Attackorder",  Move::Attack_Order },
			{  "Attract",  Move::Attract },
			{  "Aurasphere",  Move::Aura_Sphere },
			{  "Aurorabeam",  Move::Aurora_Beam },
			{  "Auroraveil",  Move::Aurora_Veil },
			{  "Autotomize",  Move::Autotomize },
			{  "Avalanche",  Move::Avalanche },
			{  "Babydolleyes",  Move::Baby_Doll_Eyes },
			{  "Baddybad",  Move::Baddy_Bad },
			{  "Banefulbunker",  Move::Baneful_Bunker },
			{  "Barrage",  Move::Barrage },
			{  "Barrier",  Move::Barrier },
			{  "Batonpass",  Move::Baton_Pass },
			{  "Beakblast",  Move::Beak_Blast },
			{  "Beatup",  Move::Beat_Up },
			{  "Belch",  Move::Belch },
			{  "Bellydrum",  Move::Belly_Drum },
			{  "Bestow",  Move::Bestow },
			{  "Bide",  Move::Bide },
			{  "Bind",  Move::Bind },
			{  "Bite",  Move::Bite },
			{  "Blackholeeclipse",  Move::Black_Hole_Eclipse },
			{  "Blastburn",  Move::Blast_Burn },
			{  "Blazekick",  Move::Blaze_Kick },
			{  "Blizzard",  Move::Blizzard },
			{  "Block",  Move::Block },
			{  "Bloomdoom",  Move::Bloom_Doom },
			{  "Blueflare",  Move::Blue_Flare },
			{  "Bodyslam",  Move::Body_Slam },
			{  "Boltstrike",  Move::Bolt_Strike },
			{  "Boneclub",  Move::Bone_Club },
			{  "Bonemerang",  Move::Bonemerang },
			{  "Bonerush",  Move::Bone_Rush },
			{  "Boomburst",  Move::Boomburst },
			{  "Bounce",  Move::Bounce },
			{  "Bouncybubble",  Move::Bouncy_Bubble },
			{  "Bravebird",  Move::Brave_Bird },
			{  "Breakneckblitz",  Move::Breakneck_Blitz },
			{  "Brickbreak",  Move::Brick_Break },
			{  "Brine",  Move::Brine },
			{  "Brutalswing",  Move::Brutal_Swing },
			{  "Bubble",  Move::Bubble },
			{  "Bubblebeam",  Move::Bubble_Beam },
			{  "Bugbite",  Move::Bug_Bite },
			{  "Bugbuzz",  Move::Bug_Buzz },
			{  "Bulkup",  Move::Bulk_Up },
			{  "Bulldoze",  Move::Bulldoze },
			{  "Bulletpunch",  Move::Bullet_Punch },
			{  "Bulletseed",  Move::Bullet_Seed },
			{  "Burnup",  Move::Burn_Up },
			{  "Buzzybuzz",  Move::Buzzy_Buzz },
			{  "Calmmind",  Move::Calm_Mind },
			{  "Camouflage",  Move::Camouflage },
			{  "Captivate",  Move::Captivate },
			{  "Catastropika",  Move::Catastropika },
			{  "Celebrate",  Move::Celebrate },
			{  "Charge",  Move::Charge },
			{  "Chargebeam",  Move::Charge_Beam },
			{  "Charm",  Move::Charm },
			{  "Chatter",  Move::Chatter },
			{  "Chipaway",  Move::Chip_Away },
			{  "Circlethrow",  Move::Circle_Throw },
			{  "Clamp",  Move::Clamp },
			{  "Clangingscales",  Move::Clanging_Scales },
			{  "Clangoroussoulblaze",  Move::Clangorous_Soulblaze },
			{  "Clearsmog",  Move::Clear_Smog },
			{  "Closecombat",  Move::Close_Combat },
			{  "Coil",  Move::Coil },
			{  "Cometpunch",  Move::Comet_Punch },
			{  "Confide",  Move::Confide },
			{  "Confuseray",  Move::Confuse_Ray },
			{  "Confusion",  Move::Confusion },
			{  "Constrict",  Move::Constrict },
			{  "Continentalcrush",  Move::Continental_Crush },
			{  "Conversion",  Move::Conversion },
			{  "Conversion2",  Move::Conversion_2 },
			{  "Copycat",  Move::Copycat },
			{  "Coreenforcer",  Move::Core_Enforcer },
			{  "Corkscrewcrash",  Move::Corkscrew_Crash },
			{  "Cosmicpower",  Move::Cosmic_Power },
			{  "Cottonguard",  Move::Cotton_Guard },
			{  "Cottonspore",  Move::Cotton_Spore },
			{  "Counter",  Move::Counter },
			{  "Covet",  Move::Covet },
			{  "Crabhammer",  Move::Crabhammer },
			{  "Craftyshield",  Move::Crafty_Shield },
			{  "Crosschop",  Move::Cross_Chop },
			{  "Crosspoison",  Move::Cross_Poison },
			{  "Crunch",  Move::Crunch },
			{  "Crushclaw",  Move::Crush_Claw },
			{  "Crushgrip",  Move::Crush_Grip },
			{  "Curse",  Move::Curse },
			{  "Cut",  Move::Cut },
			{  "Darkestlariat",  Move::Darkest_Lariat },
			{  "Darkpulse",  Move::Dark_Pulse },
			{  "Darkvoid",  Move::Dark_Void },
			{  "Dazzlinggleam",  Move::Dazzling_Gleam },
			{  "Defendorder",  Move::Defend_Order },
			{  "Defensecurl",  Move::Defense_Curl },
			{  "Defog",  Move::Defog },
			{  "Destinybond",  Move::Destiny_Bond },
			{  "Detect",  Move::Detect },
			{  "Devastatingdrake",  Move::Devastating_Drake },
			{  "Diamondstorm",  Move::Diamond_Storm },
			{  "Dig",  Move::Dig },
			{  "Disable",  Move::Disable },
			{  "Disarmingvoice",  Move::Disarming_Voice },
			{  "Discharge",  Move::Discharge },
			{  "Dive",  Move::Dive },
			{  "Dizzypunch",  Move::Dizzy_Punch },
			{  "Doomdesire",  Move::Doom_Desire },
			{  "Doubleedge",  Move::Double_Edge },
			{  "Doublehit",  Move::Double_Hit },
			{  "Doubleironbash",  Move::Double_Iron_Bash },
			{  "Doublekick",  Move::Double_Kick },
			{  "Doubleslap",  Move::Double_Slap },
			{  "Doubleteam",  Move::Double_Team },
			{  "Dracometeor",  Move::Draco_Meteor },
			{  "Dragonascent",  Move::Dragon_Ascent },
			{  "Dragonbreath",  Move::Dragon_Breath },
			{  "Dragonclaw",  Move::Dragon_Claw },
			{  "Dragondance",  Move::Dragon_Dance },
			{  "Dragonhammer",  Move::Dragon_Hammer },
			{  "Dragonpulse",  Move::Dragon_Pulse },
			{  "Dragonrage",  Move::Dragon_Rage },
			{  "Dragonrush",  Move::Dragon_Rush },
			{  "Dragontail",  Move::Dragon_Tail },
			{  "Drainingkiss",  Move::Draining_Kiss },
			{  "Drainpunch",  Move::Drain_Punch },
			{  "Dreameater",  Move::Dream_Eater },
			{  "Drillpeck",  Move::Drill_Peck },
			{  "Drillrun",  Move::Drill_Run },
			{  "Dualchop",  Move::Dual_Chop },
			{  "Dynamicpunch",  Move::Dynamic_Punch },
			{  "Earthpower",  Move::Earth_Power },
			{  "Earthquake",  Move::Earthquake },
			{  "Echoedvoice",  Move::Echoed_Voice },
			{  "Eerieimpulse",  Move::Eerie_Impulse },
			{  "Eggbomb",  Move::Egg_Bomb },
			{  "Electricterrain",  Move::Electric_Terrain },
			{  "Electrify",  Move::Electrify },
			{  "Electroball",  Move::Electro_Ball },
			{  "Electroweb",  Move::Electroweb },
			{  "Embargo",  Move::Embargo },
			{  "Ember",  Move::Ember },
			{  "Encore",  Move::Encore },
			{  "Endeavor",  Move::Endeavor },
			{  "Endure",  Move::Endure },
			{  "Energyball",  Move::Energy_Ball },
			{  "Entrainment",  Move::Entrainment },
			{  "Eruption",  Move::Eruption },
			{  "Explosion",  Move::Explosion },
			{  "Extrasensory",  Move::Extrasensory },
			{  "Extremeevoboost",  Move::Extreme_Evoboost },
			{  "Extremespeed",  Move::Extreme_Speed },
			{  "Facade",  Move::Facade },
			{  "Faintattack",  Move::Feint_Attack },
			{  "Fairylock",  Move::Fairy_Lock },
			{  "Fairywind",  Move::Fairy_Wind },
			{  "Fakeout",  Move::Fake_Out },
			{  "Faketears",  Move::Fake_Tears },
			{  "Falseswipe",  Move::False_Swipe },
			{  "Featherdance",  Move::Feather_Dance },
			{  "Feint",  Move::Feint },
			{  "Feintattack",  Move::Feint_Attack },
			{  "Fellstinger",  Move::Fell_Stinger },
			{  "Fierydance",  Move::Fiery_Dance },
			{  "Finalgambit",  Move::Final_Gambit },
			{  "Fireblast",  Move::Fire_Blast },
			{  "Firefang",  Move::Fire_Fang },
			{  "Firelash",  Move::Fire_Lash },
			{  "Firepledge",  Move::Fire_Pledge },
			{  "Firepunch",  Move::Fire_Punch },
			{  "Firespin",  Move::Fire_Spin },
			{  "Firstimpression",  Move::First_Impression },
			{  "Fissure",  Move::Fissure },
			{  "Flail",  Move::Flail },
			{  "Flameburst",  Move::Flame_Burst },
			{  "Flamecharge",  Move::Flame_Charge },
			{  "Flamethrower",  Move::Flamethrower },
			{  "Flamewheel",  Move::Flame_Wheel },
			{  "Flareblitz",  Move::Flare_Blitz },
			{  "Flash",  Move::Flash },
			{  "Flashcannon",  Move::Flash_Cannon },
			{  "Flatter",  Move::Flatter },
			{  "Fleurcannon",  Move::Fleur_Cannon },
			{  "Fling",  Move::Fling },
			{  "Floatyfall",  Move::Floaty_Fall },
			{  "Floralhealing",  Move::Floral_Healing },
			{  "Flowershield",  Move::Flower_Shield },
			{  "Fly",  Move::Fly },
			{  "Flyingpress",  Move::Flying_Press },
			{  "Focusblast",  Move::Focus_Blast },
			{  "Focusenergy",  Move::Focus_Energy },
			{  "Focuspunch",  Move::Focus_Punch },
			{  "Followme",  Move::Follow_Me },
			{  "Forcepalm",  Move::Force_Palm },
			{  "Foresight",  Move::Foresight },
			{  "Forestscurse",  Move::Forests_Curse },
			{  "Foulplay",  Move::Foul_Play },
			{  "Freezedry",  Move::Freeze_Dry },
			{  "Freezeshock",  Move::Freeze_Shock },
			{  "Freezyfrost",  Move::Freezy_Frost },
			{  "Frenzyplant",  Move::Frenzy_Plant },
			{  "Frostbreath",  Move::Frost_Breath },
			{  "Frustration",  Move::Frustration },
			{  "Furyattack",  Move::Fury_Attack },
			{  "Furycutter",  Move::Fury_Cutter },
			{  "Furyswipes",  Move::Fury_Swipes },
			{  "Fusionbolt",  Move::Fusion_Bolt },
			{  "Fusionflare",  Move::Fusion_Flare },
			{  "Futuresight",  Move::Future_Sight },
			{  "Gastroacid",  Move::Gastro_Acid },
			{  "Geargrind",  Move::Gear_Grind },
			{  "Gearup",  Move::Gear_Up },
			{  "Genesissupernova",  Move::Genesis_Supernova },
			{  "Geomancy",  Move::Geomancy },
			{  "Gigadrain",  Move::Giga_Drain },
			{  "Gigaimpact",  Move::Giga_Impact },
			{  "Gigavolthavoc",  Move::Gigavolt_Havoc },
			{  "Glaciate",  Move::Glaciate },
			{  "Glare",  Move::Glare },
			{  "Glitzyglow",  Move::Glitzy_Glow },
			{  "Grassknot",  Move::Grass_Knot },
			{  "Grasspledge",  Move::Grass_Pledge },
			{  "Grasswhistle",  Move::Grass_Whistle },
			{  "Grassyterrain",  Move::Grassy_Terrain },
			{  "Gravity",  Move::Gravity },
			{  "Growl",  Move::Growl },
			{  "Growth",  Move::Growth },
			{  "Grudge",  Move::Grudge },
			{  "Guardianofalola",  Move::Guardian_of_Alola },
			{  "Guardsplit",  Move::Guard_Split },
			{  "Guardswap",  Move::Guard_Swap },
			{  "Guillotine",  Move::Guillotine },
			{  "Gunkshot",  Move::Gunk_Shot },
			{  "Gust",  Move::Gust },
			{  "Gyroball",  Move::Gyro_Ball },
			{  "Hail",  Move::Hail },
			{  "Hammerarm",  Move::Hammer_Arm },
			{  "Happyhour",  Move::Happy_Hour },
			{  "Harden",  Move::Harden },
			{  "Haze",  Move::Haze },
			{  "Headbutt",  Move::Headbutt },
			{  "Headcharge",  Move::Head_Charge },
			{  "Headsmash",  Move::Head_Smash },
			{  "Healbell",  Move::Heal_Bell },
			{  "Healblock",  Move::Heal_Block },
			{  "Healingwish",  Move::Healing_Wish },
			{  "Healorder",  Move::Heal_Order },
			{  "Healpulse",  Move::Heal_Pulse },
			{  "Heartstamp",  Move::Heart_Stamp },
			{  "Heartswap",  Move::Heart_Swap },
			{  "Heatcrash",  Move::Heat_Crash },
			{  "Heatwave",  Move::Heat_Wave },
			{  "Heavyslam",  Move::Heavy_Slam },
			{  "Helpinghand",  Move::Helping_Hand },
			{  "Hex",  Move::Hex },
			{  "Hiddenpower",  Move::Hidden_Power },
			{  "Hiddenpowerbug",  Move::Hidden_Power },
			{  "Hiddenpowerdark",  Move::Hidden_Power },
			{  "Hiddenpowerdragon",  Move::Hidden_Power },
			{  "Hiddenpowerelectric",  Move::Hidden_Power },
			{  "Hiddenpowerfighting",  Move::Hidden_Power },
			{  "Hiddenpowerfire",  Move::Hidden_Power },
			{  "Hiddenpowerflying",  Move::Hidden_Power },
			{  "Hiddenpowerghost",  Move::Hidden_Power },
			{  "Hiddenpowergrass",  Move::Hidden_Power },
			{  "Hiddenpowerground",  Move::Hidden_Power },
			{  "Hiddenpowerice",  Move::Hidden_Power },
			{  "Hiddenpowerpoison",  Move::Hidden_Power },
			{  "Hiddenpowerpsychic",  Move::Hidden_Power },
			{  "Hiddenpowerrock",  Move::Hidden_Power },
			{  "Hiddenpowersteel",  Move::Hidden_Power },
			{  "Hiddenpowerwater",  Move::Hidden_Power },
			{  "Highhorsepower",  Move::High_Horsepower },
			{  "Highjumpkick",  Move::High_Jump_Kick },
			{  "Hijumpkick",  Move::High_Jump_Kick },
			{  "Hitselfinconfusion",  Move::Hit_Self },
			{  "Holdback",  Move::Hold_Back },
			{  "Holdhands",  Move::Hold_Hands },
			{  "Honeclaws",  Move::Hone_Claws },
			{  "Hornattack",  Move::Horn_Attack },
			{  "Horndrill",  Move::Horn_Drill },
			{  "Hornleech",  Move::Horn_Leech },
			{  "Howl",  Move::Howl },
			{  "Hurricane",  Move::Hurricane },
			{  "Hydrocannon",  Move::Hydro_Cannon },
			{  "Hydropump",  Move::Hydro_Pump },
			{  "Hydrovortex",  Move::Hydro_Vortex },
			{  "Hyperbeam",  Move::Hyper_Beam },
			{  "Hyperfang",  Move::Hyper_Fang },
			{  "Hyperspacefury",  Move::Hyperspace_Fury },
			{  "Hyperspacehole",  Move::Hyperspace_Hole },
			{  "Hypervoice",  Move::Hyper_Voice },
			{  "Hypnosis",  Move::Hypnosis },
			{  "Iceball",  Move::Ice_Ball },
			{  "Icebeam",  Move::Ice_Beam },
			{  "Iceburn",  Move::Ice_Burn },
			{  "Icefang",  Move::Ice_Fang },
			{  "Icehammer",  Move::Ice_Hammer },
			{  "Icepunch",  Move::Ice_Punch },
			{  "Iceshard",  Move::Ice_Shard },
			{  "Iciclecrash",  Move::Icicle_Crash },
			{  "Iciclespear",  Move::Icicle_Spear },
			{  "Icywind",  Move::Icy_Wind },
			{  "Imprison",  Move::Imprison },
			{  "Incinerate",  Move::Incinerate },
			{  "Inferno",  Move::Inferno },
			{  "Infernooverdrive",  Move::Inferno_Overdrive },
			{  "Infestation",  Move::Infestation },
			{  "Ingrain",  Move::Ingrain },
			{  "Instruct",  Move::Instruct },
			{  "Iondeluge",  Move::Ion_Deluge },
			{  "Irondefense",  Move::Iron_Defense },
			{  "Ironhead",  Move::Iron_Head },
			{  "Irontail",  Move::Iron_Tail },
			{  "Judgment",  Move::Judgment },
			{  "Jumpkick",  Move::Jump_Kick },
			{  "Karatechop",  Move::Karate_Chop },
			{  "Kinesis",  Move::Kinesis },
			{  "Kingsshield",  Move::Kings_Shield },
			{  "Knockoff",  Move::Knock_Off },
			{ "Landswrath",  Move::Lands_Wrath },
			{ "Laserfocus",  Move::Laser_Focus },
			{ "Lastresort",  Move::Last_Resort },
			{ "Lavaplume",  Move::Lava_Plume },
			{ "Leafage",  Move::Leafage },
			{ "Leafblade",  Move::Leaf_Blade },
			{ "Leafstorm",  Move::Leaf_Storm },
			{ "Leaftornado",  Move::Leaf_Tornado },
			{ "Leechlife",  Move::Leech_Life },
			{ "Leechseed",  Move::Leech_Seed },
			{ "Leer",  Move::Leer },
			{ "Letssnuggleforever",  Move::Lets_Snuggle_Forever },
			{ "Lick",  Move::Lick },
			{ "Lightofruin",  Move::Light_of_Ruin },
			{ "Lightscreen",  Move::Light_Screen },
			{ "Lightthatburnsthesky",  Move::Light_That_Burns_the_Sky },
			{ "Liquidation",  Move::Liquidation },
			{ "Lockon",  Move::Lock_On },
			{ "Lovelykiss",  Move::Lovely_Kiss },
			{ "Lowkick",  Move::Low_Kick },
			{ "Lowsweep",  Move::Low_Sweep },
			{ "Luckychant",  Move::Lucky_Chant },
			{ "Lunardance",  Move::Lunar_Dance },
			{ "Lunge",  Move::Lunge },
			{ "Lusterpurge",  Move::Luster_Purge },
			{ "Machpunch",  Move::Mach_Punch },
			{ "Magicalleaf",  Move::Magical_Leaf },
			{ "Magiccoat",  Move::Magic_Coat },
			{ "Magicroom",  Move::Magic_Room },
			{ "Magmastorm",  Move::Magma_Storm },
			{ "Magnetbomb",  Move::Magnet_Bomb },
			{ "Magneticflux",  Move::Magnetic_Flux },
			{ "Magnetrise",  Move::Magnet_Rise },
			{ "Magnitude",  Move::Magnitude },
			{ "Maliciousmoonsault",  Move::Malicious_Moonsault },
			{ "Matblock",  Move::Mat_Block },
			{ "Meanlook",  Move::Mean_Look },
			{ "Meditate",  Move::Meditate },
			{ "Mefirst",  Move::Me_First },
			{ "Megadrain",  Move::Mega_Drain },
			{ "Megahorn",  Move::Megahorn },
			{ "Megakick",  Move::Mega_Kick },
			{ "Megapunch",  Move::Mega_Punch },
			{ "Memento",  Move::Memento },
			{ "Menacingmoonrazemaelstrom",  Move::Menacing_Moonraze_Maelstrom },
			{ "Metalburst",  Move::Metal_Burst },
			{ "Metalclaw",  Move::Metal_Claw },
			{ "Metalsound",  Move::Metal_Sound },
			{ "Meteormash",  Move::Meteor_Mash },
			{ "Metronome",  Move::Metronome },
			{ "Milkdrink",  Move::Milk_Drink },
			{ "Mimic",  Move::Mimic },
			{ "Mindblown",  Move::Mind_Blown },
			{ "Mindreader",  Move::Mind_Reader },
			{ "Minimize",  Move::Minimize },
			{ "Miracleeye",  Move::Miracle_Eye },
			{ "Mirrorcoat",  Move::Mirror_Coat },
			{ "Mirrormove",  Move::Mirror_Move },
			{ "Mirrorshot",  Move::Mirror_Shot },
			{ "Mist",  Move::Mist },
			{ "Mistball",  Move::Mist_Ball },
			{ "Mistyterrain",  Move::Misty_Terrain },
			{ "Moonblast",  Move::Moonblast },
			{ "Moongeistbeam",  Move::Moongeist_Beam },
			{ "Moonlight",  Move::Moonlight },
			{ "Morningsun",  Move::Morning_Sun },
			{ "Mudbomb",  Move::Mud_Bomb },
			{ "Muddywater",  Move::Muddy_Water },
			{ "Mudshot",  Move::Mud_Shot },
			{ "Mudslap",  Move::Mud_Slap },
			{ "Mudsport",  Move::Mud_Sport },
			{ "Multiattack",  Move::Multi_Attack },
			{ "Mysticalfire",  Move::Mystical_Fire },
			{ "Nastyplot",  Move::Nasty_Plot },
			{ "Naturalgift",  Move::Natural_Gift },
			{ "Naturepower",  Move::Nature_Power },
			{ "Naturesmadness",  Move::Natures_Madness },
			{ "Needlearm",  Move::Needle_Arm },
			{ "Neverendingnightmare",  Move::Never_Ending_Nightmare },
			{ "Nightdaze",  Move::Night_Daze },
			{ "Nightmare",  Move::Nightmare },
			{ "Nightshade",  Move::Night_Shade },
			{ "Nightslash",  Move::Night_Slash },
			{ "Nobleroar",  Move::Noble_Roar },
			{ "Nuzzle",  Move::Nuzzle },
			{ "Oblivionwing",  Move::Oblivion_Wing },
			{ "Oceanicoperetta",  Move::Oceanic_Operetta },
			{ "Octazooka",  Move::Octazooka },
			{ "Odorsleuth",  Move::Odor_Sleuth },
			{ "Ominouswind",  Move::Ominous_Wind },
			{ "Originpulse",  Move::Origin_Pulse },
			{ "Outrage",  Move::Outrage },
			{ "Overheat",  Move::Overheat },
			{ "Painsplit",  Move::Pain_Split },
			{ "Paraboliccharge",  Move::Parabolic_Charge },
			{ "Partingshot",  Move::Parting_Shot },
			{ "Pass",  Move::Pass },
			{ "Payback",  Move::Payback },
			{ "Payday",  Move::Pay_Day },
			{ "Peck",  Move::Peck },
			{ "Perishsong",  Move::Perish_Song },
			{ "Petalblizzard",  Move::Petal_Blizzard },
			{ "Petaldance",  Move::Petal_Dance },
			{ "Phantomforce",  Move::Phantom_Force },
			{ "Photongeyser",  Move::Photon_Geyser },
			{ "Pikapapow",  Move::Pika_Papow },
			{ "Pinmissile",  Move::Pin_Missile },
			{ "Plasmafists",  Move::Plasma_Fists },
			{ "Playnice",  Move::Play_Nice },
			{ "Playrough",  Move::Play_Rough },
			{ "Pluck",  Move::Pluck },
			{ "Poisonfang",  Move::Poison_Fang },
			{ "Poisongas",  Move::Poison_Gas },
			{ "Poisonjab",  Move::Poison_Jab },
			{ "Poisonpowder",  Move::Poison_Powder },
			{ "Poisonsting",  Move::Poison_Sting },
			{ "Poisontail",  Move::Poison_Tail },
			{ "Pollenpuff",  Move::Pollen_Puff },
			{ "Pound",  Move::Pound },
			{ "Powder",  Move::Powder },
			{ "Powdersnow",  Move::Powder_Snow },
			{ "Powergem",  Move::Power_Gem },
			{ "Powersplit",  Move::Power_Split },
			{ "Powerswap",  Move::Power_Swap },
			{ "Powertrick",  Move::Power_Trick },
			{ "Powertrip",  Move::Power_Trip },
			{ "Poweruppunch",  Move::Power_Up_Punch },
			{ "Powerwhip",  Move::Power_Whip },
			{ "Precipiceblades",  Move::Precipice_Blades },
			{ "Present",  Move::Present },
			{ "Prismaticlaser",  Move::Prismatic_Laser },
			{ "Protect",  Move::Protect },
			{ "Psybeam",  Move::Psybeam },
			{ "Psychic",  Move::Psychic },
			{ "Psychicfangs",  Move::Psychic_Fangs },
			{ "Psychicterrain",  Move::Psychic_Terrain },
			{ "Psychoboost",  Move::Psycho_Boost },
			{ "Psychocut",  Move::Psycho_Cut },
			{ "Psychoshift",  Move::Psycho_Shift },
			{ "Psychup",  Move::Psych_Up },
			{ "Psyshock",  Move::Psyshock },
			{ "Psystrike",  Move::Psystrike },
			{ "Psywave",  Move::Psywave },
			{ "Pulverizingpancake",  Move::Pulverizing_Pancake },
			{ "Punishment",  Move::Punishment },
			{ "Purify",  Move::Purify },
			{ "Pursuit",  Move::Pursuit },
			{ "Quash",  Move::Quash },
			{ "Quickattack",  Move::Quick_Attack },
			{ "Quickguard",  Move::Quick_Guard },
			{ "Quiverdance",  Move::Quiver_Dance },
			{ "Rage",  Move::Rage },
			{ "Ragepowder",  Move::Rage_Powder },
			{ "Raindance",  Move::Rain_Dance },
			{ "Rapidspin",  Move::Rapid_Spin },
			{ "Razorleaf",  Move::Razor_Leaf },
			{ "Razorshell",  Move::Razor_Shell },
			{ "Razorwind",  Move::Razor_Wind },
			{ "Recover",  Move::Recover },
			{ "Recycle",  Move::Recycle },
			{ "Reflect",  Move::Reflect },
			{ "Reflecttype",  Move::Reflect_Type },
			{ "Refresh",  Move::Refresh },
			{ "Relicsong",  Move::Relic_Song },
			{ "Rest",  Move::Rest },
			{ "Retaliate",  Move::Retaliate },
			{ "Return",  Move::Return },
			{ "Return102",  Move::Return },
			{ "Revelationdance",  Move::Revelation_Dance },
			{ "Revenge",  Move::Revenge },
			{ "Reversal",  Move::Reversal },
			{ "Roar",  Move::Roar },
			{ "Roaroftime",  Move::Roar_of_Time },
			{ "Rockblast",  Move::Rock_Blast },
			{ "Rockclimb",  Move::Rock_Climb },
			{ "Rockpolish",  Move::Rock_Polish },
			{ "Rockslide",  Move::Rock_Slide },
			{ "Rocksmash",  Move::Rock_Smash },
			{ "Rockthrow",  Move::Rock_Throw },
			{ "Rocktomb",  Move::Rock_Tomb },
			{ "Rockwrecker",  Move::Rock_Wrecker },
			{ "Roleplay",  Move::Role_Play },
			{ "Rollingkick",  Move::Rolling_Kick },
			{ "Rollout",  Move::Rollout },
			{ "Roost",  Move::Roost },
			{ "Rototiller",  Move::Rototiller },
			{ "Round",  Move::Round },
			{ "Sacredfire",  Move::Sacred_Fire },
			{ "Sacredsword",  Move::Sacred_Sword },
			{ "Safeguard",  Move::Safeguard },
			{ "Sandattack",  Move::Sand_Attack },
			{ "Sandstorm",  Move::Sandstorm },
			{ "Sandtomb",  Move::Sand_Tomb },
			{ "Sappyseed",  Move::Sappy_Seed },
			{ "Savagespinout",  Move::Savage_Spin_Out },
			{ "Scald",  Move::Scald },
			{ "Scaryface",  Move::Scary_Face },
			{ "Scratch",  Move::Scratch },
			{ "Screech",  Move::Screech },
			{ "Searingshot",  Move::Searing_Shot },
			{ "Searingsunrazesmash",  Move::Searing_Sunraze_Smash },
			{ "Secretpower",  Move::Secret_Power },
			{ "Secretsword",  Move::Secret_Sword },
			{ "Seedbomb",  Move::Seed_Bomb },
			{ "Seedflare",  Move::Seed_Flare },
			{ "Seismictoss",  Move::Seismic_Toss },
			{ "Selfdestruct",  Move::Self_Destruct },
			{ "Shadowball",  Move::Shadow_Ball },
			{ "Shadowbone",  Move::Shadow_Bone },
			{ "Shadowclaw",  Move::Shadow_Claw },
			{ "Shadowforce",  Move::Shadow_Force },
			{ "Shadowpunch",  Move::Shadow_Punch },
			{ "Shadowsneak",  Move::Shadow_Sneak },
			{ "Sharpen",  Move::Sharpen },
			{ "Shatteredpsyche",  Move::Shattered_Psyche },
			{ "Sheercold",  Move::Sheer_Cold },
			{ "Shellsmash",  Move::Shell_Smash },
			{ "Shelltrap",  Move::Shell_Trap },
			{ "Shiftgear",  Move::Shift_Gear },
			{ "Shockwave",  Move::Shock_Wave },
			{ "Shoreup",  Move::Shore_Up },
			{ "Signalbeam",  Move::Signal_Beam },
			{ "Silverwind",  Move::Silver_Wind },
			{ "Simplebeam",  Move::Simple_Beam },
			{ "Sing",  Move::Sing },
			{ "Sinisterarrowraid",  Move::Sinister_Arrow_Raid },
			{ "Sizzlyslide",  Move::Sizzly_Slide },
			{ "Sketch",  Move::Sketch },
			{ "Skillswap",  Move::Skill_Swap },
			{ "Skullbash",  Move::Skull_Bash },
			{ "Skyattack",  Move::Sky_Attack },
			{ "Skydrop",  Move::Sky_Drop },
			{ "Skyuppercut",  Move::Sky_Uppercut },
			{ "Slackoff",  Move::Slack_Off },
			{ "Slam",  Move::Slam },
			{ "Slash",  Move::Slash },
			{ "Sleeppowder",  Move::Sleep_Powder },
			{ "Sleeptalk",  Move::Sleep_Talk },
			{ "Sludge",  Move::Sludge },
			{ "Sludgebomb",  Move::Sludge_Bomb },
			{ "Sludgewave",  Move::Sludge_Wave },
			{ "Smackdown",  Move::Smack_Down },
			{ "Smartstrike",  Move::Smart_Strike },
			{ "Smellingsalt",  Move::Smelling_Salts },
			{ "Smellingsalts",  Move::Smelling_Salts },
			{ "Smog",  Move::Smog },
			{ "Smokescreen",  Move::Smokescreen },
			{ "Snarl",  Move::Snarl },
			{ "Snatch",  Move::Snatch },
			{ "Snore",  Move::Snore },
			{ "Soak",  Move::Soak },
			{ "Softboiled",  Move::Soft_Boiled },
			{ "Solarbeam",  Move::Solar_Beam },
			{ "Solarblade",  Move::Solar_Blade },
			{ "Sonicboom",  Move::Sonic_Boom },
			{ "Soulstealing7starstrike",  Move::Soul_Stealing_7_Star_Strike },
			{ "Spacialrend",  Move::Spacial_Rend },
			{ "Spark",  Move::Spark },
			{ "Sparklingaria",  Move::Sparkling_Aria },
			{ "Sparklyswirl",  Move::Sparkly_Swirl },
			{ "Spectralthief",  Move::Spectral_Thief },
			{ "Speedswap",  Move::Speed_Swap },
			{ "Spiderweb",  Move::Spider_Web },
			{ "Spikecannon",  Move::Spike_Cannon },
			{ "Spikes",  Move::Spikes },
			{ "Spikyshield",  Move::Spiky_Shield },
			{ "Spiritshackle",  Move::Spirit_Shackle },
			{ "Spite",  Move::Spite },
			{ "Spitup",  Move::Spit_Up },
			{ "Splash",  Move::Splash },
			{ "Splinteredstormshards",  Move::Splintered_Stormshards },
			{ "Splishysplash",  Move::Splishy_Splash },
			{ "Spore",  Move::Spore },
			{ "Spotlight",  Move::Spotlight },
			{ "Stealthrock",  Move::Stealth_Rock },
			{ "Steameruption",  Move::Steam_Eruption },
			{ "Steamroller",  Move::Steamroller },
			{ "Steelwing",  Move::Steel_Wing },
			{ "Stickyweb",  Move::Sticky_Web },
			{ "Stockpile",  Move::Stockpile },
			{ "Stokedsparksurfer",  Move::Stoked_Sparksurfer },
			{ "Stomp",  Move::Stomp },
			{ "Stompingtantrum",  Move::Stomping_Tantrum },
			{ "Stoneedge",  Move::Stone_Edge },
			{ "Storedpower",  Move::Stored_Power },
			{ "Stormthrow",  Move::Storm_Throw },
			{ "Strength",  Move::Strength },
			{ "Strengthsap",  Move::Strength_Sap },
			{ "Stringshot",  Move::String_Shot },
			{ "Struggle",  Move::Struggle },
			{ "Strugglebug",  Move::Struggle_Bug },
			{ "Stunspore",  Move::Stun_Spore },
			{ "Submission",  Move::Submission },
			{ "Substitute",  Move::Substitute },
			{ "Subzeroslammer",  Move::Subzero_Slammer },
			{ "Suckerpunch",  Move::Sucker_Punch },
			{ "Sunnyday",  Move::Sunny_Day },
			{ "Sunsteelstrike",  Move::Sunsteel_Strike },
			{ "Superfang",  Move::Super_Fang },
			{ "Superpower",  Move::Superpower },
			{ "Supersonic",  Move::Supersonic },
			{ "Supersonicskystrike",  Move::Supersonic_Skystrike },
			{ "Surf",  Move::Surf },
			{ "Swagger",  Move::Swagger },
			{ "Swallow",  Move::Swallow },
			{ "Sweetkiss",  Move::Sweet_Kiss },
			{ "Sweetscent",  Move::Sweet_Scent },
			{ "Swift",  Move::Swift },
			{ "Switch0",  Move::Switch0 },
			{ "Switch1",  Move::Switch1 },
			{ "Switch2",  Move::Switch2 },
			{ "Switch3",  Move::Switch3 },
			{ "Switch4",  Move::Switch4 },
			{ "Switch5",  Move::Switch5 },
			{ "Switcheroo",  Move::Switcheroo },
			{ "Swordsdance",  Move::Swords_Dance },
			{ "Synchronoise",  Move::Synchronoise },
			{ "Synthesis",  Move::Synthesis },
			{ "Tackle",  Move::Tackle },
			{ "Tailglow",  Move::Tail_Glow },
			{ "Tailslap",  Move::Tail_Slap },
			{ "Tailwhip",  Move::Tail_Whip },
			{ "Tailwind",  Move::Tailwind },
			{ "Takedown",  Move::Take_Down },
			{ "Taunt",  Move::Taunt },
			{ "Tearfullook",  Move::Tearful_Look },
			{ "Technoblast",  Move::Techno_Blast },
			{ "Tectonicrage",  Move::Tectonic_Rage },
			{ "Teeterdance",  Move::Teeter_Dance },
			{ "Telekinesis",  Move::Telekinesis },
			{ "Teleport",  Move::Teleport },
			{ "Thief",  Move::Thief },
			{ "Thousandarrows",  Move::Thousand_Arrows },
			{ "Thousandwaves",  Move::Thousand_Waves },
			{ "Thrash",  Move::Thrash },
			{ "Throatchop",  Move::Throat_Chop },
			{ "Thunder",  Move::Thunder },
			{ "Thunderbolt",  Move::Thunderbolt },
			{ "Thunderfang",  Move::Thunder_Fang },
			{ "Thunderpunch",  Move::Thunder_Punch },
			{ "Thundershock",  Move::Thunder_Shock },
			{ "Thunderwave",  Move::Thunder_Wave },
			{ "Tickle",  Move::Tickle },
			{ "Topsyturvy",  Move::Topsy_Turvy },
			{ "Torment",  Move::Torment },
			{ "Toxic",  Move::Toxic },
			{ "Toxicspikes",  Move::Toxic_Spikes },
			{ "Toxicthread",  Move::Toxic_Thread },
			{ "Transform",  Move::Transform },
			{ "Triattack",  Move::Tri_Attack },
			{ "Trick",  Move::Trick },
			{ "Trickortreat",  Move::Trick_or_Treat },
			{ "Trickroom",  Move::Trick_Room },
			{ "Triplekick",  Move::Triple_Kick },
			{ "Tropkick",  Move::Trop_Kick },
			{ "Trumpcard",  Move::Trump_Card },
			{ "Twineedle",  Move::Twineedle },
			{ "Twinkletackle",  Move::Twinkle_Tackle },
			{ "Twister",  Move::Twister },
			{ "Uproar",  Move::Uproar },
			{ "Uturn",  Move::U_turn },
			{ "Vacuumwave",  Move::Vacuum_Wave },
			{ "Vcreate",  Move::V_create },
			{ "Veeveevolley",  Move::Veevee_Volley },
			{ "Venomdrench",  Move::Venom_Drench },
			{ "Venoshock",  Move::Venoshock },
			{ "Vicegrip",  Move::Vice_Grip },
			{ "Vinewhip",  Move::Vine_Whip },
			{ "Vitalthrow",  Move::Vital_Throw },
			{ "Voltswitch",  Move::Volt_Switch },
			{ "Volttackle",  Move::Volt_Tackle },
			{ "Wakeupslap",  Move::Wake_Up_Slap },
			{ "Waterfall",  Move::Waterfall },
			{ "Watergun",  Move::Water_Gun },
			{ "Waterpledge",  Move::Water_Pledge },
			{ "Waterpulse",  Move::Water_Pulse },
			{ "Watershuriken",  Move::Water_Shuriken },
			{ "Watersport",  Move::Water_Sport },
			{ "Waterspout",  Move::Water_Spout },
			{ "Weatherball",  Move::Weather_Ball },
			{ "Whirlpool",  Move::Whirlpool },
			{ "Whirlwind",  Move::Whirlwind },
			{ "Wideguard",  Move::Wide_Guard },
			{ "Wildcharge",  Move::Wild_Charge },
			{ "Willowisp",  Move::Will_O_Wisp },
			{ "Wingattack",  Move::Wing_Attack },
			{ "Wish",  Move::Wish },
			{ "Withdraw",  Move::Withdraw },
			{ "Wonderroom",  Move::Wonder_Room },
			{ "Woodhammer",  Move::Wood_Hammer },
			{ "Workup",  Move::Work_Up },
			{ "Worryseed",  Move::Worry_Seed },
			{ "Wrap",  Move::Wrap },
			{ "Wringout",  Move::Wring_Out },
			{ "Xscissor",  Move::X_Scissor },
			{ "Yawn",  Move::Yawn },
			{ "Zapcannon",  Move::Zap_Cannon },
			{ "Zenheadbutt",  Move::Zen_Headbutt },
			{ "Zingzap",  Move::Zing_Zap },
			{ "Zippyzap",  Move::Zippy_Zap }
	};

	return map[str];
}