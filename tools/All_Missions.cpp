// Lists all missions and random events of GTA V, used to keep track of which ones need to still be added to GTA V Voiceline Guesser.
#include <array>
#include <string>

// All missions needed to reach an ending, including all heist approaches/setups and all three endings
const std::array<std::string, 77> all_main_missions = {
    "Prologue",
    "Franklin_And_Lamar",
    "Repossession",
    "Complications",
    "Father_Son",
    "Chop",
    "Marriage_Counseling",
    "Daddy's_Little_Girl",
    "Friend_Request",
    "The_Long_Stretch",

    "Casing_The_Jewel_Store",
    "Carbine_Rifles",
    "Bugstars_Equipment",
    "BZ_Gas_Grenades",
    "The_Jewel_Store_Job", // Both approaches merged into one because only the beginning differs.

    "Mr_Philips",
    "Trevor_Philips_Industries",
    "Nervous_Ron",
    "Crystal_Maze",
    "Friends_Reunited",
    "Fame_Or_Shame",
    "Dead_Man_Walking",
    "Three's_Company",
    "By_The_Book",
    "Hood_Safari",
    "Did_Somebody_Say_Yoga",

    "Scouting_The_Port",
    "Minisub",
    "Cargobob",
    "The_Merryweather_Heist_Offshore",
    "The_Merryweather_Heist_Freighter",

    "Hotel_Assassination",

    "Boiler_Suits",
    "Masks",
    "Trash_Truck",
    "Tow_Truck",
    "Blitz_Play",

    "I_Fought_The_Law",
    "Eye_In_The_Sky",
    "Mr_Richards",
    "Caida_Libre",
    "Deep_Inside",
    "Minor_Turbulence",

    "Paleto_Score_Setup",
    "Predator",
    "Military_Hardware",
    "The_Paleto_Score",

    "Derailed",
    "Monkey_Business",
    "Hang_Ten",

    "Surveying_The_Score",
    "Bury_The_Hatchet",
    "Pack_Man",
    "Fresh_Meat",

    "Cleaning_Out_The_Bureau",
    "Architect's_Plans",
    "Fire_Truck",
    "The_Bureau_Raid_Fire_Crew",
    "The_Bureau_Raid_Roof_Entry",

    "The_Wrap_Up",
    "Reuniting_The_Family",
    "Legal_Trouble",
    "Lamar_Down",
    "The_Ballad_Of_Rocco",
    "Meltdown",

    "Planning_The_Big_Score",
    "Stingers",
    "Sidetracked",
    "Gauntlet_1",
    "Gauntlet_2",
    "Gauntlet_3",
    "Driller",
    "The_Big_Score_Subtle",
    "The_Big_Score_Obvious",

    "Something_Sensible",
    "The_Time's_Come",
    "The_Third_Way"
};

// All other missions, plus Pulling Favors, because Rockstar classifies it as Strangers & Freaks even though it gates story progression
const std::array<std::string, 70> all_side_missions = {
    // Tonya
    "Pulling_Favors",
    "Pulling_Another_Favor",
    "Pulling_Favors_Again",
    "Still_Pulling_Favors",
    "Pulling_One_Last_Favor",

    // Hao
    "Hao_Shift_Work",

    // Beverly / Paparazzo
    "Paparazzo",
    "Paparazzo_The_Sex_Tape",
    "Paparazzo_The_Partnership",
    "Paparazzo_The_Meltdown",
    "Paparazzo_The_Highness",
    "Paparazzo_Reality_Check",

    // Barry
    "Grass_Roots_Michael",
    "Grass_Roots_Trevor",
    "Grass_Roots_Franklin",
    "Grass_Roots_The_Pickup",
    "Grass_Roots_The_Drag",
    "Grass_Roots_The_Smoke_In",

    // Mary-Ann
    "Exercising_Demons_Michael",
    "Exercising_Demons_Franklin",
    "Exercising_Demons_Trevor",

    // Dom
    "Risk_Assessment",
    "Liquidity_Risk",
    "Targeted_Risk",
    "Uncalculated_Risk",

    // Dreyfuss
    "A_Starlet_In_Vinewood",

    // Omega
    "Far_Out",
    "The_Final_Frontier",

    // Epsilon
    "Seeking_The_Truth",
    "Accepting_The_Truth",
    "Assuming_The_Truth",
    "Chasing_The_Truth",
    "Bearing_The_Truth",
    "Delivering_The_Truth",
    "Exercising_The_Truth",
    "Unknowing_The_Truth",

    // Cletus
    "Target_Practice",
    "Fair_Game",

    // Josh
    "Extra_Commission",
    "Closing_The_Deal",
    "Surreal_Estate",
    "Breach_Of_Contract",

    // Maude
    "Special_Bonds",

    // Minute Men
    "The_Civil_Border_Patrol",
    "An_American_Welcome",
    "Minute_Man_Blues",

    // Nigel
    "Nigel_And_Mrs_Thornhill",
    "Vinewood_Souvenirs_Willy",
    "Vinewood_Souvenirs_Tyler",
    "Vinewood_Souvenirs_Kerry",
    "Vinewood_Souvenirs_Mark",
    "Vinewood_Souvenirs_Al_Di_Napoli",
    "Vinewood_Souvenirs_The_Last_Act",

    // Abigail
    "Death_At_Sea",
    "What_Lies_Beneath",

    // Trevor's Mom
    "Mrs_Philips",
    "Damaged_Goods",

    // Trevor Rampages
    "Rampage_Rednecks",
    "Rampage_Vagos",
    "Rampage_Ballas",
    "Rampage_Military",
    "Rampage_Hipsters",

    // Sasquatch
    "The_Last_One",

    // Michael's family missions
    "The_Good_Husband",
    "Doting_Dad",
    "Parenting_101",

    // Lester's assassinations
    "The_Multi_Target_Assassination",
    "The_Vice_Assassination",
    "The_Bus_Assassination",
    "The_Construction_Assassination"
};

// All random events
const std::array<std::string, 10> all_random_events = {
  "Random_Event_Arrest", "Random_Event_Bicycle_Thief", "Random_Event_Burglary", "Random_Event_Getaway_Driver", "Random_Event_Hitch_Lift",
  "Random_Event_Mugging", "Random_Event_Robbery", "Random_Event_Security_Van", "Random_Event_Stag_Dope", "Random_Event_Tow_Truck"
};