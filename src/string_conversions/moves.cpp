#include "moves.hpp"

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

template<>
auto from_string(std::string_view const str) -> Move{
	static const std::unordered_map<std::string_view, Move> map{
			{  "", Move::None },
			{  "Absorb",  Move::Absorb },
			{  "Accelerock",  Move::Accelerock },
			{  "Acid",  Move::Acid },
			{  "Acidarmor",  Move::Acid_Armor },
			{  "Aciddownpour",  Move::Acid_Downpour },
			{  "Acidspray",  Move::Acid_Spray },
			{  "Acrobatics",  Move::Acrobatics },
			{  "Acupressure",  Move::Acupressure },
			{  "AerialAce",  Move::Aerial_Ace },
			{  "AeroBlast",  Move::Aeroblast },
			{  "Afteryou",  Move::After_You },
			{  "Agility",  Move::Agility },
			{  "Aircutter",  Move::Air_Cutter },
			{  "Airslash",  Move::Air_Slash },
			{  "Alloutpummeling",  Move::All_Out_Pummeling },
			{  "Allyswitch",  Move::Ally_Switch },
			{  "Amnesia",  Move::Amnesia },
			{  "Anchorshot",  Move::Anchor_Shot },
			{  "AncientPower",  Move::Ancient_Power },
			{  "AquaJet",  Move::Aqua_Jet },
			{  "AquaRing",  Move::Aqua_Ring },
			{  "AquaTail",  Move::Aqua_Tail },
			{  "Armthrust",  Move::Arm_Thrust },
			{  "AromaTherapy",  Move::Aromatherapy },
			{  "Aromaticmist",  Move::Aromatic_Mist },
			{  "Assist",  Move::Assist },
			{  "Assurance",  Move::Assurance },
			{  "Astonish",  Move::Astonish },
			{  "AttackOrder",  Move::Attack_Order },
			{  "Attract",  Move::Attract },
			{  "AuraSphere",  Move::Aura_Sphere },
			{  "AuroraBeam",  Move::Aurora_Beam },
			{  "AuroraVeil",  Move::Aurora_Veil },
			{  "Autotomize",  Move::Autotomize },
			{  "Avalanche",  Move::Avalanche },
			{  "BabyDollEyes",  Move::Baby_Doll_Eyes },
			{  "BaddyBad",  Move::Baddy_Bad },
			{  "BanefulBunker",  Move::Baneful_Bunker },
			{  "Barrage",  Move::Barrage },
			{  "Barrier",  Move::Barrier },
			{  "BatonPass",  Move::Baton_Pass },
			{  "BeakBlast",  Move::Beak_Blast },
			{  "Beatup",  Move::Beat_Up },
			{  "Belch",  Move::Belch },
			{  "BellyDrum",  Move::Belly_Drum },
			{  "Bestow",  Move::Bestow },
			{  "Bide",  Move::Bide },
			{  "Bind",  Move::Bind },
			{  "Bite",  Move::Bite },
			{  "BlackHoleEclipse",  Move::Black_Hole_Eclipse },
			{  "BlastBurn",  Move::Blast_Burn },
			{  "BlazeKick",  Move::Blaze_Kick },
			{  "Blizzard",  Move::Blizzard },
			{  "Block",  Move::Block },
			{  "BloomDoom",  Move::Bloom_Doom },
			{  "BlueFlare",  Move::Blue_Flare },
			{  "BodySlam",  Move::Body_Slam },
			{  "Boltstrike",  Move::Bolt_Strike },
			{  "BoneClub",  Move::Bone_Club },
			{  "BoneMerang",  Move::Bonemerang },
			{  "BoneRush",  Move::Bone_Rush },
			{  "BoomBurst",  Move::Boomburst },
			{  "Bounce",  Move::Bounce },
			{  "BouncyBubble",  Move::Bouncy_Bubble },
			{  "BraveBird",  Move::Brave_Bird },
			{  "BreakNeckBlitz",  Move::Breakneck_Blitz },
			{  "BrickBreak",  Move::Brick_Break },
			{  "Brine",  Move::Brine },
			{  "BrutalSwing",  Move::Brutal_Swing },
			{  "Bubble",  Move::Bubble },
			{  "BubbleBeam",  Move::Bubble_Beam },
			{  "BugBite",  Move::Bug_Bite },
			{  "BugBuzz",  Move::Bug_Buzz },
			{  "BulkUp",  Move::Bulk_Up },
			{  "BullDoze",  Move::Bulldoze },
			{  "BulletPunch",  Move::Bullet_Punch },
			{  "BulletSeed",  Move::Bullet_Seed },
			{  "BurnUp",  Move::Burn_Up },
			{  "BuzzyBuzz",  Move::Buzzy_Buzz },
			{  "CalmMind",  Move::Calm_Mind },
			{  "Camouflage",  Move::Camouflage },
			{  "Captivate",  Move::Captivate },
			{  "Catastropika",  Move::Catastropika },
			{  "Celebrate",  Move::Celebrate },
			{  "Charge",  Move::Charge },
			{  "ChargeBeam",  Move::Charge_Beam },
			{  "Charm",  Move::Charm },
			{  "Chatter",  Move::Chatter },
			{  "ChipAway",  Move::Chip_Away },
			{  "CircleThrow",  Move::Circle_Throw },
			{  "Clamp",  Move::Clamp },
			{  "ClangingScales",  Move::Clanging_Scales },
			{  "ClangorousSoulblaze",  Move::Clangorous_Soulblaze },
			{  "ClearSmog",  Move::Clear_Smog },
			{  "CloseCombat",  Move::Close_Combat },
			{  "Coil",  Move::Coil },
			{  "CometPunch",  Move::Comet_Punch },
			{  "Confide",  Move::Confide },
			{  "ConfuseRay",  Move::Confuse_Ray },
			{  "Confusion",  Move::Confusion },
			{  "Constrict",  Move::Constrict },
			{  "ContinentalCrush",  Move::Continental_Crush },
			{  "Conversion",  Move::Conversion },
			{  "Conversion2",  Move::Conversion_2 },
			{  "Copycat",  Move::Copycat },
			{  "CoreEnforcer",  Move::Core_Enforcer },
			{  "CorkscrewCrash",  Move::Corkscrew_Crash },
			{  "CosmicPower",  Move::Cosmic_Power },
			{  "CottonGuard",  Move::Cotton_Guard },
			{  "CottonSpore",  Move::Cotton_Spore },
			{  "Counter",  Move::Counter },
			{  "Covet",  Move::Covet },
			{  "CrabHammer",  Move::Crabhammer },
			{  "CraftyShield",  Move::Crafty_Shield },
			{  "CrossChop",  Move::Cross_Chop },
			{  "CrossPoison",  Move::Cross_Poison },
			{  "Crunch",  Move::Crunch },
			{  "CrushClaw",  Move::Crush_Claw },
			{  "CrushGrip",  Move::Crush_Grip },
			{  "Curse",  Move::Curse },
			{  "Cut",  Move::Cut },
			{  "DarkestLariat",  Move::Darkest_Lariat },
			{  "DarkPulse",  Move::Dark_Pulse },
			{  "DarkVoid",  Move::Dark_Void },
			{  "DazzlingGleam",  Move::Dazzling_Gleam },
			{  "DefendOrder",  Move::Defend_Order },
			{  "DefenseCurl",  Move::Defense_Curl },
			{  "Defog",  Move::Defog },
			{  "DestinyBond",  Move::Destiny_Bond },
			{  "Detect",  Move::Detect },
			{  "DevastatingDrake",  Move::Devastating_Drake },
			{  "DiamondStorm",  Move::Diamond_Storm },
			{  "Dig",  Move::Dig },
			{  "Disable",  Move::Disable },
			{  "DisarmingVoice",  Move::Disarming_Voice },
			{  "Discharge",  Move::Discharge },
			{  "Dive",  Move::Dive },
			{  "DizzyPunch",  Move::Dizzy_Punch },
			{  "DoomDesire",  Move::Doom_Desire },
			{  "DoubleEdge",  Move::Double_Edge },
			{  "DoubleHit",  Move::Double_Hit },
			{  "DoubleIronBash",  Move::Double_Iron_Bash },
			{  "DoubleKick",  Move::Double_Kick },
			{  "DoubleSlap",  Move::Double_Slap },
			{  "DoublTteam",  Move::Double_Team },
			{  "DracoMeteor",  Move::Draco_Meteor },
			{  "DragonAscent",  Move::Dragon_Ascent },
			{  "DragonBreath",  Move::Dragon_Breath },
			{  "DragonClaw",  Move::Dragon_Claw },
			{  "DragonDance",  Move::Dragon_Dance },
			{  "DragonHammer",  Move::Dragon_Hammer },
			{  "DragonPulse",  Move::Dragon_Pulse },
			{  "DragonRage",  Move::Dragon_Rage },
			{  "DragonRush",  Move::Dragon_Rush },
			{  "DragonTail",  Move::Dragon_Tail },
			{  "DrainingKiss",  Move::Draining_Kiss },
			{  "DrainPunch",  Move::Drain_Punch },
			{  "DreamEater",  Move::Dream_Eater },
			{  "DrillPeck",  Move::Drill_Peck },
			{  "DrillRun",  Move::Drill_Run },
			{  "DualChop",  Move::Dual_Chop },
			{  "DynamicPunch",  Move::Dynamic_Punch },
			{  "EarthPower",  Move::Earth_Power },
			{  "Earthquake",  Move::Earthquake },
			{  "EchoedVoice",  Move::Echoed_Voice },
			{  "EerieImpulse",  Move::Eerie_Impulse },
			{  "EggBomb",  Move::Egg_Bomb },
			{  "Electricterrain",  Move::Electric_Terrain },
			{  "Electrify",  Move::Electrify },
			{  "ElectroBall",  Move::Electro_Ball },
			{  "ElectroWeb",  Move::Electroweb },
			{  "Embargo",  Move::Embargo },
			{  "Ember",  Move::Ember },
			{  "Encore",  Move::Encore },
			{  "Endeavor",  Move::Endeavor },
			{  "Endure",  Move::Endure },
			{  "EnergyBall",  Move::Energy_Ball },
			{  "Entrainment",  Move::Entrainment },
			{  "Eruption",  Move::Eruption },
			{  "Explosion",  Move::Explosion },
			{  "Extrasensory",  Move::Extrasensory },
			{  "ExtremeEvoboost",  Move::Extreme_Evoboost },
			{  "ExtremeSpeed",  Move::Extreme_Speed },
			{  "Facade",  Move::Facade },
			{  "FaintAttack",  Move::Feint_Attack },
			{  "FairyLock",  Move::Fairy_Lock },
			{  "FairyWind",  Move::Fairy_Wind },
			{  "FakeOut",  Move::Fake_Out },
			{  "FakeTears",  Move::Fake_Tears },
			{  "FalseSwipe",  Move::False_Swipe },
			{  "FeatherDance",  Move::Feather_Dance },
			{  "Feint",  Move::Feint },
			{  "FeintAttack",  Move::Feint_Attack },
			{  "FellStinger",  Move::Fell_Stinger },
			{  "FieryDance",  Move::Fiery_Dance },
			{  "FinalGambit",  Move::Final_Gambit },
			{  "FireBlast",  Move::Fire_Blast },
			{  "FireFang",  Move::Fire_Fang },
			{  "FireLash",  Move::Fire_Lash },
			{  "FirePledge",  Move::Fire_Pledge },
			{  "FirePunch",  Move::Fire_Punch },
			{  "FireSpin",  Move::Fire_Spin },
			{  "FirstImpression",  Move::First_Impression },
			{  "Fissure",  Move::Fissure },
			{  "Flail",  Move::Flail },
			{  "FlameBurst",  Move::Flame_Burst },
			{  "FlameCharge",  Move::Flame_Charge },
			{  "Flamethrower",  Move::Flamethrower },
			{  "FlameWheel",  Move::Flame_Wheel },
			{  "FlareBlitz",  Move::Flare_Blitz },
			{  "Flash",  Move::Flash },
			{  "FlashCannon",  Move::Flash_Cannon },
			{  "Flatter",  Move::Flatter },
			{  "FleurCannon",  Move::Fleur_Cannon },
			{  "Fling",  Move::Fling },
			{  "FloatyFall",  Move::Floaty_Fall },
			{  "FloralHealing",  Move::Floral_Healing },
			{  "FlowerShield",  Move::Flower_Shield },
			{  "Fly",  Move::Fly },
			{  "FlyingPress",  Move::Flying_Press },
			{  "FocusBlast",  Move::Focus_Blast },
			{  "FocusEnergy",  Move::Focus_Energy },
			{  "FocusPunch",  Move::Focus_Punch },
			{  "FollowMe",  Move::Follow_Me },
			{  "ForcePalm",  Move::Force_Palm },
			{  "ForeSight",  Move::Foresight },
			{  "ForestsCurse",  Move::Forests_Curse },
			{  "FoulPlay",  Move::Foul_Play },
			{  "FreezeDry",  Move::Freeze_Dry },
			{  "FreezeShock",  Move::Freeze_Shock },
			{  "FreezyFrost",  Move::Freezy_Frost },
			{  "FrenzyPlant",  Move::Frenzy_Plant },
			{  "FrostBreath",  Move::Frost_Breath },
			{  "Frustration",  Move::Frustration },
			{  "FuryAttack",  Move::Fury_Attack },
			{  "FuryCutter",  Move::Fury_Cutter },
			{  "FurySwipes",  Move::Fury_Swipes },
			{  "FusionBolt",  Move::Fusion_Bolt },
			{  "FusionFlare",  Move::Fusion_Flare },
			{  "FutureSight",  Move::Future_Sight },
			{  "GastroAcid",  Move::Gastro_Acid },
			{  "GearGrind",  Move::Gear_Grind },
			{  "GearUp",  Move::Gear_Up },
			{  "GenesisSupernova",  Move::Genesis_Supernova },
			{  "Geomancy",  Move::Geomancy },
			{  "GigaDrain",  Move::Giga_Drain },
			{  "GigaImpact",  Move::Giga_Impact },
			{  "GigavoltHavoc",  Move::Gigavolt_Havoc },
			{  "Glaciate",  Move::Glaciate },
			{  "Glare",  Move::Glare },
			{  "GlitzyGlow",  Move::Glitzy_Glow },
			{  "GrassKnot",  Move::Grass_Knot },
			{  "GrassPledge",  Move::Grass_Pledge },
			{  "GrassWhistle",  Move::Grass_Whistle },
			{  "GrassyTerrain",  Move::Grassy_Terrain },
			{  "Gravity",  Move::Gravity },
			{  "Growl",  Move::Growl },
			{  "Growth",  Move::Growth },
			{  "Grudge",  Move::Grudge },
			{  "GuardianOfAlola",  Move::Guardian_of_Alola },
			{  "GuardSplit",  Move::Guard_Split },
			{  "GuardSwap",  Move::Guard_Swap },
			{  "Guillotine",  Move::Guillotine },
			{  "GunkShot",  Move::Gunk_Shot },
			{  "Gust",  Move::Gust },
			{  "GyroBall",  Move::Gyro_Ball },
			{  "Hail",  Move::Hail },
			{  "HammerArm",  Move::Hammer_Arm },
			{  "HappyHour",  Move::Happy_Hour },
			{  "Harden",  Move::Harden },
			{  "Haze",  Move::Haze },
			{  "Headbutt",  Move::Headbutt },
			{  "HeadCharge",  Move::Head_Charge },
			{  "HeadSmash",  Move::Head_Smash },
			{  "HealBell",  Move::Heal_Bell },
			{  "HealBlock",  Move::Heal_Block },
			{  "HealingWish",  Move::Healing_Wish },
			{  "HealOrder",  Move::Heal_Order },
			{  "HealPulse",  Move::Heal_Pulse },
			{  "HeartStamp",  Move::Heart_Stamp },
			{  "HeartSwap",  Move::Heart_Swap },
			{  "HeatCrash",  Move::Heat_Crash },
			{  "HeatWave",  Move::Heat_Wave },
			{  "HeavySlam",  Move::Heavy_Slam },
			{  "HelpingHand",  Move::Helping_Hand },
			{  "Hex",  Move::Hex },
			{  "HiddenPower",  Move::Hidden_Power },
			{  "HiddenPowerBug",  Move::Hidden_Power },
			{  "HiddenPowerDark",  Move::Hidden_Power },
			{  "HiddenPowerDragon",  Move::Hidden_Power },
			{  "HiddenPowerElectric",  Move::Hidden_Power },
			{  "HiddenPowerFighting",  Move::Hidden_Power },
			{  "HiddenPowerFire",  Move::Hidden_Power },
			{  "HiddenPowerFlying",  Move::Hidden_Power },
			{  "HiddenPowerGhost",  Move::Hidden_Power },
			{  "HiddenPowerGrass",  Move::Hidden_Power },
			{  "HiddenPowerGround",  Move::Hidden_Power },
			{  "HiddenPowerIce",  Move::Hidden_Power },
			{  "HiddenPowerPoison",  Move::Hidden_Power },
			{  "HiddenPowerPsychic",  Move::Hidden_Power },
			{  "HiddenPowerRock",  Move::Hidden_Power },
			{  "HiddenPowerSteel",  Move::Hidden_Power },
			{  "HiddenPowerWater",  Move::Hidden_Power },
			{  "HighHorsepower",  Move::High_Horsepower },
			{  "HighJumpkick",  Move::High_Jump_Kick },
			{  "HiJumpKick",  Move::High_Jump_Kick },
			{  "Hitselfinconfusion",  Move::Hit_Self },
			{  "HoldBack",  Move::Hold_Back },
			{  "HoldHands",  Move::Hold_Hands },
			{  "HoneClaws",  Move::Hone_Claws },
			{  "HornAttack",  Move::Horn_Attack },
			{  "HornDrill",  Move::Horn_Drill },
			{  "HornLeech",  Move::Horn_Leech },
			{  "Howl",  Move::Howl },
			{  "Hurricane",  Move::Hurricane },
			{  "HydroCannon",  Move::Hydro_Cannon },
			{  "HydroPump",  Move::Hydro_Pump },
			{  "HydroVortex",  Move::Hydro_Vortex },
			{  "HyperBeam",  Move::Hyper_Beam },
			{  "HyperFang",  Move::Hyper_Fang },
			{  "HyperspaceFury",  Move::Hyperspace_Fury },
			{  "HyperspaceHole",  Move::Hyperspace_Hole },
			{  "HyperVoice",  Move::Hyper_Voice },
			{  "Hypnosis",  Move::Hypnosis },
			{  "IceBall",  Move::Ice_Ball },
			{  "IceBeam",  Move::Ice_Beam },
			{  "IceBurn",  Move::Ice_Burn },
			{  "IceFang",  Move::Ice_Fang },
			{  "IceHammer",  Move::Ice_Hammer },
			{  "IcePunch",  Move::Ice_Punch },
			{  "IceShard",  Move::Ice_Shard },
			{  "IcicleCrash",  Move::Icicle_Crash },
			{  "IcicleSpear",  Move::Icicle_Spear },
			{  "IcyWind",  Move::Icy_Wind },
			{  "Imprison",  Move::Imprison },
			{  "Incinerate",  Move::Incinerate },
			{  "Inferno",  Move::Inferno },
			{  "InfernoOverdrive",  Move::Inferno_Overdrive },
			{  "Infestation",  Move::Infestation },
			{  "Ingrain",  Move::Ingrain },
			{  "Instruct",  Move::Instruct },
			{  "IonDeluge",  Move::Ion_Deluge },
			{  "IronDefense",  Move::Iron_Defense },
			{  "IronHead",  Move::Iron_Head },
			{  "IronTail",  Move::Iron_Tail },
			{  "Judgment",  Move::Judgment },
			{  "JumpKick",  Move::Jump_Kick },
			{  "KarateChop",  Move::Karate_Chop },
			{  "Kinesis",  Move::Kinesis },
			{  "KingsShield",  Move::Kings_Shield },
			{  "KnockOff",  Move::Knock_Off },
			{ "LandsWrath",  Move::Lands_Wrath },
			{ "LaserFocus",  Move::Laser_Focus },
			{ "LastResort",  Move::Last_Resort },
			{ "LavaPlume",  Move::Lava_Plume },
			{ "Leafage",  Move::Leafage },
			{ "LeafBlade",  Move::Leaf_Blade },
			{ "LeafStorm",  Move::Leaf_Storm },
			{ "LeafTornado",  Move::Leaf_Tornado },
			{ "LeechLife",  Move::Leech_Life },
			{ "LeechSeed",  Move::Leech_Seed },
			{ "Leer",  Move::Leer },
			{ "LetsSnuggleForever",  Move::Lets_Snuggle_Forever },
			{ "Lick",  Move::Lick },
			{ "LightOfRuin",  Move::Light_of_Ruin },
			{ "LightScreen",  Move::Light_Screen },
			{ "LightThatBurnsTheSky",  Move::Light_That_Burns_the_Sky },
			{ "Liquidation",  Move::Liquidation },
			{ "LockOn",  Move::Lock_On },
			{ "LovelyKiss",  Move::Lovely_Kiss },
			{ "LowKick",  Move::Low_Kick },
			{ "LowSweep",  Move::Low_Sweep },
			{ "LuckyChant",  Move::Lucky_Chant },
			{ "LunarDance",  Move::Lunar_Dance },
			{ "Lunge",  Move::Lunge },
			{ "LusterPurge",  Move::Luster_Purge },
			{ "MachPunch",  Move::Mach_Punch },
			{ "MagicalLeaf",  Move::Magical_Leaf },
			{ "MagicCoat",  Move::Magic_Coat },
			{ "MagicRoom",  Move::Magic_Room },
			{ "MagmaStorm",  Move::Magma_Storm },
			{ "MagnetBomb",  Move::Magnet_Bomb },
			{ "MagneticFlux",  Move::Magnetic_Flux },
			{ "MagnetRise",  Move::Magnet_Rise },
			{ "Magnitude",  Move::Magnitude },
			{ "MaliciousMoonsault",  Move::Malicious_Moonsault },
			{ "MatBlock",  Move::Mat_Block },
			{ "MeanLook",  Move::Mean_Look },
			{ "Meditate",  Move::Meditate },
			{ "MeFirst",  Move::Me_First },
			{ "MegaDrain",  Move::Mega_Drain },
			{ "Megahorn",  Move::Megahorn },
			{ "MegaKick",  Move::Mega_Kick },
			{ "MegaPunch",  Move::Mega_Punch },
			{ "Memento",  Move::Memento },
			{ "MenacingMoonrazeMaelstrom",  Move::Menacing_Moonraze_Maelstrom },
			{ "MetalBurst",  Move::Metal_Burst },
			{ "MetalClaw",  Move::Metal_Claw },
			{ "MetalSound",  Move::Metal_Sound },
			{ "MeteorMash",  Move::Meteor_Mash },
			{ "Metronome",  Move::Metronome },
			{ "MilkDrink",  Move::Milk_Drink },
			{ "Mimic",  Move::Mimic },
			{ "MindBlown",  Move::Mind_Blown },
			{ "MindReader",  Move::Mind_Reader },
			{ "Minimize",  Move::Minimize },
			{ "MiracleEye",  Move::Miracle_Eye },
			{ "MirrorCoat",  Move::Mirror_Coat },
			{ "MirrorMove",  Move::Mirror_Move },
			{ "MirrorShot",  Move::Mirror_Shot },
			{ "Mist",  Move::Mist },
			{ "MistBall",  Move::Mist_Ball },
			{ "MistyTerrain",  Move::Misty_Terrain },
			{ "MoonBlast",  Move::Moonblast },
			{ "MoongeistBeam",  Move::Moongeist_Beam },
			{ "Moonlight",  Move::Moonlight },
			{ "MorningSun",  Move::Morning_Sun },
			{ "Mudbomb",  Move::Mud_Bomb },
			{ "MuddyWater",  Move::Muddy_Water },
			{ "MudShot",  Move::Mud_Shot },
			{ "MudSlap",  Move::Mud_Slap },
			{ "MudSport",  Move::Mud_Sport },
			{ "MultiAttack",  Move::Multi_Attack },
			{ "MysticalFire",  Move::Mystical_Fire },
			{ "NastyPlot",  Move::Nasty_Plot },
			{ "NaturalGift",  Move::Natural_Gift },
			{ "NaturePower",  Move::Nature_Power },
			{ "NaturesMadness",  Move::Natures_Madness },
			{ "NeedleArm",  Move::Needle_Arm },
			{ "NeverEndingNightmare",  Move::Never_Ending_Nightmare },
			{ "NightDaze",  Move::Night_Daze },
			{ "NightMare",  Move::Nightmare },
			{ "NightShade",  Move::Night_Shade },
			{ "NightSlash",  Move::Night_Slash },
			{ "NobleRoar",  Move::Noble_Roar },
			{ "Nuzzle",  Move::Nuzzle },
			{ "OblivionWing",  Move::Oblivion_Wing },
			{ "OceanicOperetta",  Move::Oceanic_Operetta },
			{ "Octazooka",  Move::Octazooka },
			{ "OdorSleuth",  Move::Odor_Sleuth },
			{ "OminousWind",  Move::Ominous_Wind },
			{ "OriginPulse",  Move::Origin_Pulse },
			{ "Outrage",  Move::Outrage },
			{ "Overheat",  Move::Overheat },
			{ "PainSplit",  Move::Pain_Split },
			{ "ParabolicCharge",  Move::Parabolic_Charge },
			{ "PartingShot",  Move::Parting_Shot },
			{ "Pass",  Move::Pass },
			{ "Payback",  Move::Payback },
			{ "PayDay",  Move::Pay_Day },
			{ "Peck",  Move::Peck },
			{ "PerishSong",  Move::Perish_Song },
			{ "PetalBlizzard",  Move::Petal_Blizzard },
			{ "PetalDance",  Move::Petal_Dance },
			{ "PhantomForce",  Move::Phantom_Force },
			{ "PhotonGeyser",  Move::Photon_Geyser },
			{ "PikaPapow",  Move::Pika_Papow },
			{ "PinMissile",  Move::Pin_Missile },
			{ "PlasmaFists",  Move::Plasma_Fists },
			{ "PlayNice",  Move::Play_Nice },
			{ "PlayRough",  Move::Play_Rough },
			{ "Pluck",  Move::Pluck },
			{ "PoisonFang",  Move::Poison_Fang },
			{ "PoisonGas",  Move::Poison_Gas },
			{ "PoisonJab",  Move::Poison_Jab },
			{ "PoisonPowder",  Move::Poison_Powder },
			{ "PoisonSting",  Move::Poison_Sting },
			{ "PoisonTail",  Move::Poison_Tail },
			{ "PollenPuff",  Move::Pollen_Puff },
			{ "Pound",  Move::Pound },
			{ "Powder",  Move::Powder },
			{ "PowderSnow",  Move::Powder_Snow },
			{ "PowerGem",  Move::Power_Gem },
			{ "PowerSplit",  Move::Power_Split },
			{ "PowerSwap",  Move::Power_Swap },
			{ "PowerTrick",  Move::Power_Trick },
			{ "PowerTrip",  Move::Power_Trip },
			{ "PowerUpPunch",  Move::Power_Up_Punch },
			{ "PowerWhip",  Move::Power_Whip },
			{ "PrecipiceBlades",  Move::Precipice_Blades },
			{ "Present",  Move::Present },
			{ "PrismaticLaser",  Move::Prismatic_Laser },
			{ "Protect",  Move::Protect },
			{ "Psybeam",  Move::Psybeam },
			{ "Psychic",  Move::Psychic },
			{ "PsychicFangs",  Move::Psychic_Fangs },
			{ "PsychicTerrain",  Move::Psychic_Terrain },
			{ "PsychoBoost",  Move::Psycho_Boost },
			{ "PsychoCut",  Move::Psycho_Cut },
			{ "PsychoShift",  Move::Psycho_Shift },
			{ "PsychUp",  Move::Psych_Up },
			{ "Psyshock",  Move::Psyshock },
			{ "Psystrike",  Move::Psystrike },
			{ "Psywave",  Move::Psywave },
			{ "PulverizingPancake",  Move::Pulverizing_Pancake },
			{ "Punishment",  Move::Punishment },
			{ "Purify",  Move::Purify },
			{ "Pursuit",  Move::Pursuit },
			{ "Quash",  Move::Quash },
			{ "QuickAttack",  Move::Quick_Attack },
			{ "QuickGuard",  Move::Quick_Guard },
			{ "QuiverDance",  Move::Quiver_Dance },
			{ "Rage",  Move::Rage },
			{ "RagePowder",  Move::Rage_Powder },
			{ "RainDance",  Move::Rain_Dance },
			{ "RapidSpin",  Move::Rapid_Spin },
			{ "RazorLeaf",  Move::Razor_Leaf },
			{ "RazorShell",  Move::Razor_Shell },
			{ "RazorWind",  Move::Razor_Wind },
			{ "Recover",  Move::Recover },
			{ "Recycle",  Move::Recycle },
			{ "Reflect",  Move::Reflect },
			{ "ReflectType",  Move::Reflect_Type },
			{ "Refresh",  Move::Refresh },
			{ "RelicSong",  Move::Relic_Song },
			{ "Rest",  Move::Rest },
			{ "Retaliate",  Move::Retaliate },
			{ "Return",  Move::Return },
			{ "Return102",  Move::Return },
			{ "RevelationDance",  Move::Revelation_Dance },
			{ "Revenge",  Move::Revenge },
			{ "Reversal",  Move::Reversal },
			{ "Roar",  Move::Roar },
			{ "RoarOfTime",  Move::Roar_of_Time },
			{ "RockBlast",  Move::Rock_Blast },
			{ "RockClimb",  Move::Rock_Climb },
			{ "RockPolish",  Move::Rock_Polish },
			{ "RockSlide",  Move::Rock_Slide },
			{ "RockSmash",  Move::Rock_Smash },
			{ "RockThrow",  Move::Rock_Throw },
			{ "RockTomb",  Move::Rock_Tomb },
			{ "RockWrecker",  Move::Rock_Wrecker },
			{ "RolePlay",  Move::Role_Play },
			{ "RollingKick",  Move::Rolling_Kick },
			{ "Rollout",  Move::Rollout },
			{ "Roost",  Move::Roost },
			{ "Rototiller",  Move::Rototiller },
			{ "Round",  Move::Round },
			{ "SacredFire",  Move::Sacred_Fire },
			{ "SacredSword",  Move::Sacred_Sword },
			{ "Safeguard",  Move::Safeguard },
			{ "SandAttack",  Move::Sand_Attack },
			{ "Sandstorm",  Move::Sandstorm },
			{ "SandTomb",  Move::Sand_Tomb },
			{ "SappySeed",  Move::Sappy_Seed },
			{ "SavageSpinOut",  Move::Savage_Spin_Out },
			{ "Scald",  Move::Scald },
			{ "ScaryFace",  Move::Scary_Face },
			{ "Scratch",  Move::Scratch },
			{ "Screech",  Move::Screech },
			{ "SearingShot",  Move::Searing_Shot },
			{ "SearingSunrazeSmash",  Move::Searing_Sunraze_Smash },
			{ "SecretPower",  Move::Secret_Power },
			{ "SecretSword",  Move::Secret_Sword },
			{ "SeedBomb",  Move::Seed_Bomb },
			{ "SeedFlare",  Move::Seed_Flare },
			{ "SeismicToss",  Move::Seismic_Toss },
			{ "SelfDestruct",  Move::Self_Destruct },
			{ "ShadowBall",  Move::Shadow_Ball },
			{ "ShadowBone",  Move::Shadow_Bone },
			{ "ShadowClaw",  Move::Shadow_Claw },
			{ "ShadowForce",  Move::Shadow_Force },
			{ "ShadowPunch",  Move::Shadow_Punch },
			{ "ShadowSneak",  Move::Shadow_Sneak },
			{ "Sharpen",  Move::Sharpen },
			{ "ShatteredPsyche",  Move::Shattered_Psyche },
			{ "SheerCold",  Move::Sheer_Cold },
			{ "ShellSmash",  Move::Shell_Smash },
			{ "ShellTrap",  Move::Shell_Trap },
			{ "ShiftGear",  Move::Shift_Gear },
			{ "ShockWave",  Move::Shock_Wave },
			{ "ShoreUp",  Move::Shore_Up },
			{ "SignalBeam",  Move::Signal_Beam },
			{ "SilverWind",  Move::Silver_Wind },
			{ "SimpleBeam",  Move::Simple_Beam },
			{ "Sing",  Move::Sing },
			{ "SinisterArrowRaid",  Move::Sinister_Arrow_Raid },
			{ "SizzlySlide",  Move::Sizzly_Slide },
			{ "Sketch",  Move::Sketch },
			{ "SkillSwap",  Move::Skill_Swap },
			{ "SkullBash",  Move::Skull_Bash },
			{ "SkyAttack",  Move::Sky_Attack },
			{ "SkyDrop",  Move::Sky_Drop },
			{ "SkyUppercut",  Move::Sky_Uppercut },
			{ "SlackOff",  Move::Slack_Off },
			{ "Slam",  Move::Slam },
			{ "Slash",  Move::Slash },
			{ "SleepPowder",  Move::Sleep_Powder },
			{ "SleepTalk",  Move::Sleep_Talk },
			{ "Sludge",  Move::Sludge },
			{ "SludgeBomb",  Move::Sludge_Bomb },
			{ "SludgeWave",  Move::Sludge_Wave },
			{ "SmackDown",  Move::Smack_Down },
			{ "SmartStrike",  Move::Smart_Strike },
			{ "SmellingSalt",  Move::Smelling_Salts },
			{ "SmellingSalts",  Move::Smelling_Salts },
			{ "Smog",  Move::Smog },
			{ "Smokescreen",  Move::Smokescreen },
			{ "Snarl",  Move::Snarl },
			{ "Snatch",  Move::Snatch },
			{ "Snore",  Move::Snore },
			{ "Soak",  Move::Soak },
			{ "SoftBoiled",  Move::Soft_Boiled },
			{ "SolarBeam",  Move::Solar_Beam },
			{ "SolarBlade",  Move::Solar_Blade },
			{ "SonicBoom",  Move::Sonic_Boom },
			{ "SoulStealing7StarStrike",  Move::Soul_Stealing_7_Star_Strike },
			{ "SpacialRend",  Move::Spacial_Rend },
			{ "Spark",  Move::Spark },
			{ "SparklingAria",  Move::Sparkling_Aria },
			{ "SparklySwirl",  Move::Sparkly_Swirl },
			{ "SpectralThief",  Move::Spectral_Thief },
			{ "SpeedSwap",  Move::Speed_Swap },
			{ "SpiderWeb",  Move::Spider_Web },
			{ "SpikeCannon",  Move::Spike_Cannon },
			{ "Spikes",  Move::Spikes },
			{ "SpikyShield",  Move::Spiky_Shield },
			{ "SpiritShackle",  Move::Spirit_Shackle },
			{ "Spite",  Move::Spite },
			{ "SpitUp",  Move::Spit_Up },
			{ "Splash",  Move::Splash },
			{ "SplinteredStormshards",  Move::Splintered_Stormshards },
			{ "SplishySplash",  Move::Splishy_Splash },
			{ "Spore",  Move::Spore },
			{ "Spotlight",  Move::Spotlight },
			{ "StealthRock",  Move::Stealth_Rock },
			{ "SteamEruption",  Move::Steam_Eruption },
			{ "Steamroller",  Move::Steamroller },
			{ "SteelWing",  Move::Steel_Wing },
			{ "StickyWeb",  Move::Sticky_Web },
			{ "Stockpile",  Move::Stockpile },
			{ "StokedSparksurfer",  Move::Stoked_Sparksurfer },
			{ "Stomp",  Move::Stomp },
			{ "StompingTantrum",  Move::Stomping_Tantrum },
			{ "StoneEdge",  Move::Stone_Edge },
			{ "StoredPower",  Move::Stored_Power },
			{ "StormThrow",  Move::Storm_Throw },
			{ "Strength",  Move::Strength },
			{ "StrengthSap",  Move::Strength_Sap },
			{ "StringShot",  Move::String_Shot },
			{ "Struggle",  Move::Struggle },
			{ "StruggleBug",  Move::Struggle_Bug },
			{ "StunSpore",  Move::Stun_Spore },
			{ "Submission",  Move::Submission },
			{ "Substitute",  Move::Substitute },
			{ "SubzeroSlammer",  Move::Subzero_Slammer },
			{ "SuckerPunch",  Move::Sucker_Punch },
			{ "SunnyDay",  Move::Sunny_Day },
			{ "SunsteelStrike",  Move::Sunsteel_Strike },
			{ "SuperFang",  Move::Super_Fang },
			{ "Superpower",  Move::Superpower },
			{ "Supersonic",  Move::Supersonic },
			{ "SupersonicSkystrike",  Move::Supersonic_Skystrike },
			{ "Surf",  Move::Surf },
			{ "Swagger",  Move::Swagger },
			{ "Swallow",  Move::Swallow },
			{ "SweetKiss",  Move::Sweet_Kiss },
			{ "SweetScent",  Move::Sweet_Scent },
			{ "Swift",  Move::Swift },
			{ "Switch0",  Move::Switch0 },
			{ "Switch1",  Move::Switch1 },
			{ "Switch2",  Move::Switch2 },
			{ "Switch3",  Move::Switch3 },
			{ "Switch4",  Move::Switch4 },
			{ "Switch5",  Move::Switch5 },
			{ "Switcheroo",  Move::Switcheroo },
			{ "SwordsDance",  Move::Swords_Dance },
			{ "Synchronoise",  Move::Synchronoise },
			{ "Synthesis",  Move::Synthesis },
			{ "Tackle",  Move::Tackle },
			{ "TailGlow",  Move::Tail_Glow },
			{ "TailSlap",  Move::Tail_Slap },
			{ "TailWhip",  Move::Tail_Whip },
			{ "Tailwind",  Move::Tailwind },
			{ "TakeDown",  Move::Take_Down },
			{ "Taunt",  Move::Taunt },
			{ "TearfulLook",  Move::Tearful_Look },
			{ "TechnoBlast",  Move::Techno_Blast },
			{ "TectonicRage",  Move::Tectonic_Rage },
			{ "TeeterDance",  Move::Teeter_Dance },
			{ "Telekinesis",  Move::Telekinesis },
			{ "Teleport",  Move::Teleport },
			{ "Thief",  Move::Thief },
			{ "ThousandArrows",  Move::Thousand_Arrows },
			{ "ThousandWaves",  Move::Thousand_Waves },
			{ "Thrash",  Move::Thrash },
			{ "ThroatChop",  Move::Throat_Chop },
			{ "Thunder",  Move::Thunder },
			{ "Thunderbolt",  Move::Thunderbolt },
			{ "ThunderFang",  Move::Thunder_Fang },
			{ "ThunderPunch",  Move::Thunder_Punch },
			{ "ThunderShock",  Move::Thunder_Shock },
			{ "ThunderWave",  Move::Thunder_Wave },
			{ "Tickle",  Move::Tickle },
			{ "TopsyTurvy",  Move::Topsy_Turvy },
			{ "Torment",  Move::Torment },
			{ "Toxic",  Move::Toxic },
			{ "ToxicSpikes",  Move::Toxic_Spikes },
			{ "ToxicThread",  Move::Toxic_Thread },
			{ "Transform",  Move::Transform },
			{ "TriAttack",  Move::Tri_Attack },
			{ "Trick",  Move::Trick },
			{ "TrickOrTreat",  Move::Trick_or_Treat },
			{ "TrickRoom",  Move::Trick_Room },
			{ "TripleKick",  Move::Triple_Kick },
			{ "TropKick",  Move::Trop_Kick },
			{ "TrumpCard",  Move::Trump_Card },
			{ "Twineedle",  Move::Twineedle },
			{ "TwinkleTackle",  Move::Twinkle_Tackle },
			{ "Twister",  Move::Twister },
			{ "Uproar",  Move::Uproar },
			{ "UTurn",  Move::U_turn },
			{ "VacuumWave",  Move::Vacuum_Wave },
			{ "VCreate",  Move::V_create },
			{ "VeeveeBolley",  Move::Veevee_Volley },
			{ "VenomDrench",  Move::Venom_Drench },
			{ "Venoshock",  Move::Venoshock },
			{ "ViceGrip",  Move::Vice_Grip },
			{ "VineWhip",  Move::Vine_Whip },
			{ "VitalThrow",  Move::Vital_Throw },
			{ "VoltSwitch",  Move::Volt_Switch },
			{ "VoltTackle",  Move::Volt_Tackle },
			{ "WakeUpSlap",  Move::Wake_Up_Slap },
			{ "Waterfall",  Move::Waterfall },
			{ "WaterGun",  Move::Water_Gun },
			{ "WaterPledge",  Move::Water_Pledge },
			{ "WaterPulse",  Move::Water_Pulse },
			{ "WaterShuriken",  Move::Water_Shuriken },
			{ "WaterSport",  Move::Water_Sport },
			{ "WaterSpout",  Move::Water_Spout },
			{ "WeatherBall",  Move::Weather_Ball },
			{ "Whirlpool",  Move::Whirlpool },
			{ "Whirlwind",  Move::Whirlwind },
			{ "WideGuard",  Move::Wide_Guard },
			{ "WildCharge",  Move::Wild_Charge },
			{ "WillOWisp",  Move::Will_O_Wisp },
			{ "WingAttack",  Move::Wing_Attack },
			{ "Wish",  Move::Wish },
			{ "Withdraw",  Move::Withdraw },
			{ "WonderRoom",  Move::Wonder_Room },
			{ "WoodHammer",  Move::Wood_Hammer },
			{ "WorkUp",  Move::Work_Up },
			{ "WorrySeed",  Move::Worry_Seed },
			{ "Wrap",  Move::Wrap },
			{ "WringOut",  Move::Wring_Out },
			{ "XScissor",  Move::X_Scissor },
			{ "Yawn",  Move::Yawn },
			{ "ZapCannon",  Move::Zap_Cannon },
			{ "ZenHeadbutt",  Move::Zen_Headbutt },
			{ "ZingZap",  Move::Zing_Zap },
			{ "ZippyZap",  Move::Zippy_Zap }
	};

	return map.at(str);
}