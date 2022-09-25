#pragma once

#include <array>

#include "battle.hpp"

namespace Tests{
    namespace Moves{
        static constexpr AttackMove absorb(Move::Absorb);
        static constexpr AttackMove acid(Move::Acid);
        static constexpr AttackMove acid_armor(Move::Acid_Armor);
        static constexpr AttackMove agility(Move::Agility);
        static constexpr AttackMove amnesia(Move::Amnesia);
        static constexpr AttackMove aurora_beam(Move::Aurora_Beam);
        static constexpr AttackMove barrage(Move::Barrage);
        static constexpr AttackMove barrier(Move::Barrier);
        static constexpr AttackMove bide(Move::Bide);
        static constexpr AttackMove bind(Move::Bind);
        static constexpr AttackMove bite(Move::Bite);
        static constexpr AttackMove blizzard(Move::Blizzard);
        static constexpr AttackMove body_slam(Move::Body_Slam);
        static constexpr AttackMove bone_club(Move::Bone_Club);
        static constexpr AttackMove bonemerang(Move::Bonemerang);
        static constexpr AttackMove bubble(Move::Bubble);
        static constexpr AttackMove bubble_beam(Move::Bubble_Beam);
        static constexpr AttackMove clamp(Move::Clamp);
        static constexpr AttackMove comet_punch(Move::Comet_Punch);
        static constexpr AttackMove confuse_ray(Move::Confuse_Ray);
        static constexpr AttackMove confusion(Move::Confusion);
        static constexpr AttackMove constrict(Move::Constrict);
        static constexpr AttackMove conversion(Move::Conversion);
        static constexpr AttackMove counter(Move::Counter);
        static constexpr AttackMove crabhammer(Move::Crabhammer);
        static constexpr AttackMove cut(Move::Cut);
        static constexpr AttackMove defense_curl(Move::Defense_Curl);
        static constexpr AttackMove dig(Move::Dig);
        static constexpr AttackMove disable(Move::Disable);
        static constexpr AttackMove dizzy_punch(Move::Dizzy_Punch);
        static constexpr AttackMove double_edge(Move::Double_Edge);
        static constexpr AttackMove double_kick(Move::Double_Kick);
        static constexpr AttackMove double_slap(Move::Double_Slap);
        static constexpr AttackMove double_team(Move::Double_Team);
        static constexpr AttackMove dragon_rage(Move::Dragon_Rage);
        static constexpr AttackMove dream_eater(Move::Dream_Eater);
        static constexpr AttackMove drill_peck(Move::Drill_Peck);
        static constexpr AttackMove earthquake(Move::Earthquake);
        static constexpr AttackMove egg_bomb(Move::Egg_Bomb);
        static constexpr AttackMove ember(Move::Ember);
        static constexpr AttackMove explosion(Move::Explosion);
        static constexpr AttackMove fire_blast(Move::Fire_Blast);
        static constexpr AttackMove fire_punch(Move::Fire_Punch);
        static constexpr AttackMove fire_spin(Move::Fire_Spin);
        static constexpr AttackMove fissure(Move::Fissure);
        static constexpr AttackMove flamethrower(Move::Flamethrower);
        static constexpr AttackMove flash(Move::Flash);
        static constexpr AttackMove fly(Move::Fly);
        static constexpr AttackMove focus_energy(Move::Focus_Energy);
        static constexpr AttackMove fury_attack(Move::Fury_Attack);
        static constexpr AttackMove fury_swipes(Move::Fury_Swipes);
        static constexpr AttackMove glare(Move::Glare);
        static constexpr AttackMove growl(Move::Growl);
        static constexpr AttackMove growth(Move::Growth);
        static constexpr AttackMove guillotine(Move::Guillotine);
        static constexpr AttackMove gust(Move::Gust);
        static constexpr AttackMove harden(Move::Harden);
        static constexpr AttackMove haze(Move::Haze);
        static constexpr AttackMove headbutt(Move::Headbutt);
        static constexpr AttackMove high_jump_kick(Move::High_Jump_Kick);
        static constexpr AttackMove horn_attack(Move::Horn_Attack);
        static constexpr AttackMove horn_drill(Move::Horn_Drill);
        static constexpr AttackMove hydro_pump(Move::Hydro_Pump);
        static constexpr AttackMove hyper_beam(Move::Hyper_Beam);
        static constexpr AttackMove hyper_fang(Move::Hyper_Fang);
        static constexpr AttackMove hypnosis(Move::Hypnosis);
        static constexpr AttackMove ice_beam(Move::Ice_Beam);
        static constexpr AttackMove ice_punch(Move::Ice_Punch);
        static constexpr AttackMove jump_kick(Move::Jump_Kick);
        static constexpr AttackMove karate_chop(Move::Karate_Chop);
        static constexpr AttackMove kinesis(Move::Kinesis);
        static constexpr AttackMove leech_life(Move::Leech_Life);
        static constexpr AttackMove leech_seed(Move::Leech_Seed);
        static constexpr AttackMove leer(Move::Leer);
        static constexpr AttackMove lick(Move::Lick);
        static constexpr AttackMove light_screen(Move::Light_Screen);
        static constexpr AttackMove lovely_kiss(Move::Lovely_Kiss);
        static constexpr AttackMove low_kick(Move::Low_Kick);
        static constexpr AttackMove meditate(Move::Meditate);
        static constexpr AttackMove mega_drain(Move::Mega_Drain);
        static constexpr AttackMove mega_kick(Move::Mega_Kick);
        static constexpr AttackMove mega_punch(Move::Mega_Punch);
        static constexpr AttackMove metronome(Move::Metronome);
        static constexpr AttackMove mimic(Move::Mimic);
        static constexpr AttackMove minimize(Move::Minimize);
        static constexpr AttackMove mirror_move(Move::Mirror_Move);
        static constexpr AttackMove mist(Move::Mist);
        static constexpr AttackMove night_shade(Move::Night_Shade);
        static constexpr AttackMove pay_day(Move::Pay_Day);
        static constexpr AttackMove peck(Move::Peck);
        static constexpr AttackMove petal_dance(Move::Petal_Dance);
        static constexpr AttackMove pin_missile(Move::Pin_Missile);
        static constexpr AttackMove poison_gas(Move::Poison_Gas);
        static constexpr AttackMove poison_powder(Move::Poison_Powder);
        static constexpr AttackMove poison_sting(Move::Poison_Sting);
        static constexpr AttackMove pound(Move::Pound);
        static constexpr AttackMove psybeam(Move::Psybeam);
        static constexpr AttackMove psychic(Move::Psychic);
        static constexpr AttackMove psywave(Move::Psywave);
        static constexpr AttackMove quick_attack(Move::Quick_Attack);
        static constexpr AttackMove rage(Move::Rage);
        static constexpr AttackMove razor_leaf(Move::Razor_Leaf);
        static constexpr AttackMove razor_wind(Move::Razor_Wind);
        static constexpr AttackMove recover(Move::Recover);
        static constexpr AttackMove reflect(Move::Reflect);
        static constexpr AttackMove rest(Move::Rest);
        static constexpr AttackMove roar(Move::Roar);
        static constexpr AttackMove rock_slide(Move::Rock_Slide);
        static constexpr AttackMove rock_throw(Move::Rock_Throw);
        static constexpr AttackMove rolling_kick(Move::Rolling_Kick);
        static constexpr AttackMove sand_attack(Move::Sand_Attack);
        static constexpr AttackMove scratch(Move::Scratch);
        static constexpr AttackMove screech(Move::Screech);
        static constexpr AttackMove seismic_toss(Move::Seismic_Toss);
        static constexpr AttackMove self_destruct(Move::Self_Destruct);
        static constexpr AttackMove sharpen(Move::Sharpen);
        static constexpr AttackMove sing(Move::Sing);
        static constexpr AttackMove skull_bash(Move::Skull_Bash);
        static constexpr AttackMove sky_attack(Move::Sky_Attack);
        static constexpr AttackMove slam(Move::Slam);
        static constexpr AttackMove slash(Move::Slash);
        static constexpr AttackMove sleep_powder(Move::Sleep_Powder);
        static constexpr AttackMove sludge(Move::Sludge);
        static constexpr AttackMove smog(Move::Smog);
        static constexpr AttackMove smokescreen(Move::Smokescreen);
        static constexpr AttackMove soft_boiled(Move::Soft_Boiled);
        static constexpr AttackMove solar_beam(Move::Solar_Beam);
        static constexpr AttackMove sonic_boom(Move::Sonic_Boom);
        static constexpr AttackMove spike_cannon(Move::Spike_Cannon);
        static constexpr AttackMove splash(Move::Splash);
        static constexpr AttackMove spore(Move::Spore);
        static constexpr AttackMove stomp(Move::Stomp);
        static constexpr AttackMove strength(Move::Strength);
        static constexpr AttackMove string_shot(Move::String_Shot);
        static constexpr AttackMove struggle(Move::Struggle);
        static constexpr AttackMove stun_spore(Move::Stun_Spore);
        static constexpr AttackMove submission(Move::Submission);
        static constexpr AttackMove substitute(Move::Substitute);
        static constexpr AttackMove super_fang(Move::Super_Fang);
        static constexpr AttackMove supersonic(Move::Supersonic);
        static constexpr AttackMove surf(Move::Surf);
        static constexpr AttackMove swift(Move::Swift);
        static constexpr AttackMove swords_dance(Move::Swords_Dance);
        static constexpr AttackMove tackle(Move::Tackle);
        static constexpr AttackMove tail_whip(Move::Tail_Whip);
        static constexpr AttackMove take_down(Move::Take_Down);
        static constexpr AttackMove teleport(Move::Teleport);
        static constexpr AttackMove thrash(Move::Thrash);
        static constexpr AttackMove thunder(Move::Thunder);
        static constexpr AttackMove thunder_punch(Move::Thunder_Punch);
        static constexpr AttackMove thunder_shock(Move::Thunder_Shock);
        static constexpr AttackMove thunder_wave(Move::Thunder_Wave);
        static constexpr AttackMove thunderbolt(Move::Thunderbolt);
        static constexpr AttackMove toxic(Move::Toxic);
        static constexpr AttackMove transform(Move::Transform);
        static constexpr AttackMove tri_attack(Move::Tri_Attack);
        static constexpr AttackMove twineedle(Move::Twineedle);
        static constexpr AttackMove vice_grip(Move::Vice_Grip);
        static constexpr AttackMove vine_whip(Move::Vine_Whip);
        static constexpr AttackMove water_gun(Move::Water_Gun);
        static constexpr AttackMove waterfall(Move::Waterfall);
        static constexpr AttackMove whirlwind(Move::Whirlwind);
        static constexpr AttackMove wing_attack(Move::Wing_Attack);
        static constexpr AttackMove withdraw(Move::Withdraw);
        static constexpr AttackMove wrap(Move::Wrap);
        static constexpr AttackMove aeroblast(Move::Aeroblast);
        static constexpr AttackMove ancient_power(Move::Ancient_Power);
        static constexpr AttackMove attract(Move::Attract);
        static constexpr AttackMove baton_pass(Move::Baton_Pass);
        static constexpr AttackMove beat_up(Move::Beat_Up);
        static constexpr AttackMove belly_drum(Move::Belly_Drum);
        static constexpr AttackMove bone_rush(Move::Bone_Rush);
        static constexpr AttackMove charm(Move::Charm);
        static constexpr AttackMove conversion_2(Move::Conversion_2);
        static constexpr AttackMove cotton_spore(Move::Cotton_Spore);
        static constexpr AttackMove cross_chop(Move::Cross_Chop);
        static constexpr AttackMove crunch(Move::Crunch);
        static constexpr AttackMove curse(Move::Curse);
        static constexpr AttackMove destiny_bond(Move::Destiny_Bond);
        static constexpr AttackMove detect(Move::Detect);
        static constexpr AttackMove dragon_breath(Move::Dragon_Breath);
        static constexpr AttackMove dynamic_punch(Move::Dynamic_Punch);
        static constexpr AttackMove encore(Move::Encore);
        static constexpr AttackMove endure(Move::Endure);
        static constexpr AttackMove extreme_speed(Move::Extreme_Speed);
        static constexpr AttackMove false_swipe(Move::False_Swipe);
        static constexpr AttackMove feint_attack(Move::Feint_Attack);
        static constexpr AttackMove flail(Move::Flail);
        static constexpr AttackMove flame_wheel(Move::Flame_Wheel);
        static constexpr AttackMove foresight(Move::Foresight);
        static constexpr AttackMove frustration(Move::Frustration);
        static constexpr AttackMove fury_cutter(Move::Fury_Cutter);
        static constexpr AttackMove future_sight(Move::Future_Sight);
        static constexpr AttackMove giga_drain(Move::Giga_Drain);
        static constexpr AttackMove heal_bell(Move::Heal_Bell);
        static constexpr AttackMove hidden_power(Move::Hidden_Power);
        static constexpr AttackMove icy_wind(Move::Icy_Wind);
        static constexpr AttackMove iron_tail(Move::Iron_Tail);
        static constexpr AttackMove lock_on(Move::Lock_On);
        static constexpr AttackMove mach_punch(Move::Mach_Punch);
        static constexpr AttackMove magnitude(Move::Magnitude);
        static constexpr AttackMove mean_look(Move::Mean_Look);
        static constexpr AttackMove megahorn(Move::Megahorn);
        static constexpr AttackMove metal_claw(Move::Metal_Claw);
        static constexpr AttackMove milk_drink(Move::Milk_Drink);
        static constexpr AttackMove mind_reader(Move::Mind_Reader);
        static constexpr AttackMove mirror_coat(Move::Mirror_Coat);
        static constexpr AttackMove moonlight(Move::Moonlight);
        static constexpr AttackMove morning_sun(Move::Morning_Sun);
        static constexpr AttackMove mud_slap(Move::Mud_Slap);
        static constexpr AttackMove nightmare(Move::Nightmare);
        static constexpr AttackMove octazooka(Move::Octazooka);
        static constexpr AttackMove outrage(Move::Outrage);
        static constexpr AttackMove pain_split(Move::Pain_Split);
        static constexpr AttackMove perish_song(Move::Perish_Song);
        static constexpr AttackMove powder_snow(Move::Powder_Snow);
        static constexpr AttackMove present(Move::Present);
        static constexpr AttackMove protect(Move::Protect);
        static constexpr AttackMove psych_up(Move::Psych_Up);
        static constexpr AttackMove pursuit(Move::Pursuit);
        static constexpr AttackMove rain_dance(Move::Rain_Dance);
        static constexpr AttackMove rapid_spin(Move::Rapid_Spin);
        static constexpr AttackMove return_(Move::Return);
        static constexpr AttackMove reversal(Move::Reversal);
        static constexpr AttackMove rock_smash(Move::Rock_Smash);
        static constexpr AttackMove rollout(Move::Rollout);
        static constexpr AttackMove sacred_fire(Move::Sacred_Fire);
        static constexpr AttackMove safeguard(Move::Safeguard);
        static constexpr AttackMove sandstorm(Move::Sandstorm);
        static constexpr AttackMove scary_face(Move::Scary_Face);
        static constexpr AttackMove shadow_ball(Move::Shadow_Ball);
        static constexpr AttackMove sketch(Move::Sketch);
        static constexpr AttackMove sleep_talk(Move::Sleep_Talk);
        static constexpr AttackMove sludge_bomb(Move::Sludge_Bomb);
        static constexpr AttackMove snore(Move::Snore);
        static constexpr AttackMove spark(Move::Spark);
        static constexpr AttackMove spider_web(Move::Spider_Web);
        static constexpr AttackMove spikes(Move::Spikes);
        static constexpr AttackMove spite(Move::Spite);
        static constexpr AttackMove steel_wing(Move::Steel_Wing);
        static constexpr AttackMove sunny_day(Move::Sunny_Day);
        static constexpr AttackMove swagger(Move::Swagger);
        static constexpr AttackMove sweet_kiss(Move::Sweet_Kiss);
        static constexpr AttackMove sweet_scent(Move::Sweet_Scent);
        static constexpr AttackMove synthesis(Move::Synthesis);
        static constexpr AttackMove thief(Move::Thief);
        static constexpr AttackMove triple_kick(Move::Triple_Kick);
        static constexpr AttackMove twister(Move::Twister);
        static constexpr AttackMove vital_throw(Move::Vital_Throw);
        static constexpr AttackMove whirlpool(Move::Whirlpool);
        static constexpr AttackMove zap_cannon(Move::Zap_Cannon);
        static constexpr AttackMove aerial_ace(Move::Aerial_Ace);
        static constexpr AttackMove air_cutter(Move::Air_Cutter);
        static constexpr AttackMove arm_thrust(Move::Arm_Thrust);
        static constexpr AttackMove aromatherapy(Move::Aromatherapy);
        static constexpr AttackMove assist(Move::Assist);
        static constexpr AttackMove astonish(Move::Astonish);
        static constexpr AttackMove blast_burn(Move::Blast_Burn);
        static constexpr AttackMove blaze_kick(Move::Blaze_Kick);
        static constexpr AttackMove block(Move::Block);
        static constexpr AttackMove bounce(Move::Bounce);
        static constexpr AttackMove brick_break(Move::Brick_Break);
        static constexpr AttackMove bulk_up(Move::Bulk_Up);
        static constexpr AttackMove bullet_seed(Move::Bullet_Seed);
        static constexpr AttackMove calm_mind(Move::Calm_Mind);
        static constexpr AttackMove camouflage(Move::Camouflage);
        static constexpr AttackMove charge(Move::Charge);
        static constexpr AttackMove cosmic_power(Move::Cosmic_Power);
        static constexpr AttackMove covet(Move::Covet);
        static constexpr AttackMove crush_claw(Move::Crush_Claw);
        static constexpr AttackMove dive(Move::Dive);
        static constexpr AttackMove doom_desire(Move::Doom_Desire);
        static constexpr AttackMove dragon_claw(Move::Dragon_Claw);
        static constexpr AttackMove dragon_dance(Move::Dragon_Dance);
        static constexpr AttackMove endeavor(Move::Endeavor);
        static constexpr AttackMove eruption(Move::Eruption);
        static constexpr AttackMove extrasensory(Move::Extrasensory);
        static constexpr AttackMove facade(Move::Facade);
        static constexpr AttackMove fake_out(Move::Fake_Out);
        static constexpr AttackMove fake_tears(Move::Fake_Tears);
        static constexpr AttackMove feather_dance(Move::Feather_Dance);
        static constexpr AttackMove flatter(Move::Flatter);
        static constexpr AttackMove focus_punch(Move::Focus_Punch);
        static constexpr AttackMove follow_me(Move::Follow_Me);
        static constexpr AttackMove frenzy_plant(Move::Frenzy_Plant);
        static constexpr AttackMove grass_whistle(Move::Grass_Whistle);
        static constexpr AttackMove grudge(Move::Grudge);
        static constexpr AttackMove hail(Move::Hail);
        static constexpr AttackMove heat_wave(Move::Heat_Wave);
        static constexpr AttackMove helping_hand(Move::Helping_Hand);
        static constexpr AttackMove howl(Move::Howl);
        static constexpr AttackMove hydro_cannon(Move::Hydro_Cannon);
        static constexpr AttackMove hyper_voice(Move::Hyper_Voice);
        static constexpr AttackMove ice_ball(Move::Ice_Ball);
        static constexpr AttackMove icicle_spear(Move::Icicle_Spear);
        static constexpr AttackMove imprison(Move::Imprison);
        static constexpr AttackMove ingrain(Move::Ingrain);
        static constexpr AttackMove iron_defense(Move::Iron_Defense);
        static constexpr AttackMove knock_off(Move::Knock_Off);
        static constexpr AttackMove leaf_blade(Move::Leaf_Blade);
        static constexpr AttackMove luster_purge(Move::Luster_Purge);
        static constexpr AttackMove magic_coat(Move::Magic_Coat);
        static constexpr AttackMove magical_leaf(Move::Magical_Leaf);
        static constexpr AttackMove memento(Move::Memento);
        static constexpr AttackMove metal_sound(Move::Metal_Sound);
        static constexpr AttackMove meteor_mash(Move::Meteor_Mash);
        static constexpr AttackMove mist_ball(Move::Mist_Ball);
        static constexpr AttackMove mud_shot(Move::Mud_Shot);
        static constexpr AttackMove mud_sport(Move::Mud_Sport);
        static constexpr AttackMove muddy_water(Move::Muddy_Water);
        static constexpr AttackMove nature_power(Move::Nature_Power);
        static constexpr AttackMove needle_arm(Move::Needle_Arm);
        static constexpr AttackMove odor_sleuth(Move::Odor_Sleuth);
        static constexpr AttackMove overheat(Move::Overheat);
        static constexpr AttackMove poison_fang(Move::Poison_Fang);
        static constexpr AttackMove poison_tail(Move::Poison_Tail);
        static constexpr AttackMove psycho_boost(Move::Psycho_Boost);
        static constexpr AttackMove recycle(Move::Recycle);
        static constexpr AttackMove refresh(Move::Refresh);
        static constexpr AttackMove revenge(Move::Revenge);
        static constexpr AttackMove rock_blast(Move::Rock_Blast);
        static constexpr AttackMove rock_tomb(Move::Rock_Tomb);
        static constexpr AttackMove role_play(Move::Role_Play);
        static constexpr AttackMove sand_tomb(Move::Sand_Tomb);
        static constexpr AttackMove secret_power(Move::Secret_Power);
        static constexpr AttackMove shadow_punch(Move::Shadow_Punch);
        static constexpr AttackMove sheer_cold(Move::Sheer_Cold);
        static constexpr AttackMove shock_wave(Move::Shock_Wave);
        static constexpr AttackMove signal_beam(Move::Signal_Beam);
        static constexpr AttackMove silver_wind(Move::Silver_Wind);
        static constexpr AttackMove skill_swap(Move::Skill_Swap);
        static constexpr AttackMove sky_uppercut(Move::Sky_Uppercut);
        static constexpr AttackMove slack_off(Move::Slack_Off);
        static constexpr AttackMove smelling_salts(Move::Smelling_Salts);
        static constexpr AttackMove snatch(Move::Snatch);
        static constexpr AttackMove spit_up(Move::Spit_Up);
        static constexpr AttackMove stockpile(Move::Stockpile);
        static constexpr AttackMove superpower(Move::Superpower);
        static constexpr AttackMove swallow(Move::Swallow);
        static constexpr AttackMove tail_glow(Move::Tail_Glow);
        static constexpr AttackMove taunt(Move::Taunt);
        static constexpr AttackMove teeter_dance(Move::Teeter_Dance);
        static constexpr AttackMove tickle(Move::Tickle);
        static constexpr AttackMove torment(Move::Torment);
        static constexpr AttackMove trick(Move::Trick);
        static constexpr AttackMove uproar(Move::Uproar);
        static constexpr AttackMove volt_tackle(Move::Volt_Tackle);
        static constexpr AttackMove water_pulse(Move::Water_Pulse);
        static constexpr AttackMove water_sport(Move::Water_Sport);
        static constexpr AttackMove water_spout(Move::Water_Spout);
        static constexpr AttackMove weather_ball(Move::Weather_Ball);
        static constexpr AttackMove will_o_wisp(Move::Will_O_Wisp);
        static constexpr AttackMove wish(Move::Wish);
        static constexpr AttackMove yawn(Move::Yawn);
    };
};