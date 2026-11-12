// All implemented voicelines bundled into a single file to be nicely included in the executable itself
#pragma once

#include <string> // Required for std::string
#include <unordered_map> // Used for bundled_voicelines

inline const std::unordered_map<std::string, std::string> bundled_voicelines = {
    {"Bugstars_Equipment", R"(
[Easy][Michael]:    Alright, Lester, we got a pest control van.

-If the player hasn't completed BZ Gas Grenades yet
  One line split into 2:
[Hard][Lester]:    Good. I've got a line on the knockout gas. 
[Hard][Lester]:    It's made in some lab on the coast, but two shipments a day come through the city from the north east, taking it to the airport.
[Extreme][Michael]:    Alright, I'll see if I can jump one.
)"},
    {"BZ_Gas_Grenades", R"(
[Easy][Michael]:    Hey, Lest, I got the goodnight gas.
 
-If the player also completed Bugstars Equipment
[Normal][Lester]:    That's everything we need. I'll put out word that the score is ready to go.
 
-If the player hasn't completed Bugstars Equipment yet
[Normal][Lester]:    Ahh, good. Once we have the pest control van, we'll be ready to go.
)"},
    {"Carbine_Rifles", R"(
[Normal][Michael]:    Alright, Lester, I got us the tac' team rifles.
[Normal][Lester]:    Alright, then this score is ready to go. Come inside and meet the crew.
)"},
    {"Casing_The_Jewel_Store", R"(
-If Michael is not wearing a suit
[Normal][Lester]:    Mike, I said look nice. Can you put a suit on, please? 
[Normal][Lester]:    You're wasting my time. When you look decent, we can go. 
[Normal][Lester]:    We're not casing a joint with you looking like that. 
[Hard][Lester]:    You're boring me, Michael. Just go change. 
[Normal][Lester]:    The sooner you change, the sooner we can find you a score.
 
Michael enters the garment factory.
[Extreme][Michael]:    The hell is this place?
[Normal][Lester]:    A garment factory. I needed a job that didn't require me to do anything apart from, uh, paying taxes.
[Easy][Lester]:    The Holy Grail - the Union Depository. Now, they say it cannot be hit. Hasn't been yet.
[Easy][Michael]:    Look, I just owe some Mexican a couple of million bucks 'cause I wrecked his girlfriend's house. I don't need to go crazy here.
[Extreme][Lester]:    Which Mexican?
[Normal][Lester]:    He's not supposed to be very nice.
[Normal][Michael]:    Oh, when I met him, he was charming.
[Easy][Lester]:    Oh, erm, let's see, either we hit a bank in the sticks, or we do a store. Which do you like?
[Easy][Michael]:    Well... a store's usually easier, but I gotta make a big take.
[Easy][Lester]:    Well, gems it is, then. Let's go to Vangelico, buy ourselves an engagement ring.
[Normal][Michael]:    Oh, we're gonna need a crew. I can round up some of the old guys?
[Hard][Lester]:    There are no old guys. 
[Normal][Lester]:    Moses, ironically, he found Jesus. All those Irish crazies, they mostly just disappeared, that crew from the south, they all went down. 
[Normal][Lester]:    There was a... an Eastern European guy making moves in Liberty City, but... nah, he went quiet.
 
Michael and Lester go outside and drive off.
[Normal][Michael]:    Alright. Well, we're gonna need a crew. You got any contacts in LS or not?
[Normal][Lester]:    I've been working with someone, but they're too unpredictable. I'll have to reach out to some other guys.
[Normal][Lester]:    The shop's on Little Portola. Your FIB buddies, they, uh, know you're back in business?
[Hard][Michael]:    FIB buddies? What are you talking about?
  One line split into 2:
[Hard][Lester]:    I checked out the WPP thing. It doesn't look like any WitSec program I'm aware of. 
[Normal][Lester]:    Well, for starters, they don't put witnesses up in multimillion dollar mansions in Rockford Hills.
[Hard][Michael]:    Oh, maybe they thought this would be the best cover.
  One line split into 3:
[Normal][Lester]:    And most witnesses don't transfer five-figure sums into a particular FIB agent's bank account every month. 
[Hard][Lester]:    Of course, the money gets moved around and washed through a number of fronts, but the trail is there: deposits and withdrawals, the same sum every month. 
[Normal][Lester]:    Agent Dave Norton. White middle-aged divorcee, unremarkable career except for one incident: the shooting of a notorious stick-up man, Michael Townley.
[Hard][Michael]:    Yeah, yeah, yeah, yeah, alright. Lester, I'm very impressed.
[Normal][Lester]:    Look, we can talk about this another time. Take these glasses.
[Hard][Michael]:    My eyesight's fine.
[Normal][Lester]:    They're fitted with a camera and a radio relay. I'm going to run the operation from the car, while you're in the store getting what we need.
 
Michael goes to Vangelico.
[Normal][Lester]:    Okay, we need shots of the security features - the alarm system, ventilation, cameras.
[Normal][Lester]:    The alarm keypad is on the left when you come in, on the wall by the side door. Glasses are live, shoot away.
 
-If the player leaves before the info is obtained
[Hard][Lester]:    You've still got work to do in the jewel store.
 
Michael takes pictures of the security systems.
-If one feature in the shot
[Normal][Lester]:    Ah, okay, that's their alarm. Now, can you get me an air vent and one of the cameras?
[Normal][Lester]:    That's the ventilation. Go get a camera and the alarm.
[Normal][Lester]:    Alright, I got an idea of their CCTV setup. Can you shoot an air vent and the alarm keypad.
 
-If two features in the shot
[Normal][Lester]:    So, uh, that's the cameras and the alarm. When you've got a shot of the vents, we're done.
[Normal][Lester]:    What we got here? Surveillance and ventilation. Now all I'm after's the alarm.
[Normal][Lester]:    Okay. That's the alarm and the vent. We still need a shot of the surveillance system.
 
-If three features in the shot
  One line split into 2:
[Easy][Lester]:    Shot's come through. Camera: check. Alarms: check. Vents: check. 
[Normal][Lester]:    Good work, now speak to the assistant and see if there's anything else we need to know.
 
Michael approaches the store's cashier.
[Easy][Michael]:    Hey, beautiful. I need to pick up a little something for the woman in my life, well, one of 'em.
[Easy][Michael]:    Cheap, thank God. This ain't my wife we're talking about. I don't know...I don't want to spend too much, I'm thinking, maybe... ten grand?
[Easy][Michael]:    Alright. So, these things built to last, or am I just paying for the Vangelico logo here?
[Normal][Michael]:    Alright, I think you just made a sale. I'm gonna take a look around, think about it, come back to you, baby. Don't go anywhere.
 
Michael heads back to the car and drives to the roof access.
[Normal][Lester]:    Almost. I need to get eyes on the roof of the building, see where the ventilation comes out.
[Hard][Lester]:    Drive us around the block. We gotta find a way up to the roof.
[Extreme][Lester]:    Look, there. Some construction.
[Hard][Michael]:    Ah, if they're gutting the place, I might be able to get to the roof.
 
Michael heads to the rooftops.
[Hard][Michael]:    So, you keep up with the old crew?
[Normal][Lester]:    Well, after your death/disappearance, there wasn't much holding us together.
[Hard][Michael]:    Yeah, you see him at all, after the incident?
[Hard][Lester]:    I kept tabs on him for a while, needed to know that he didn't blame me.
[Hard][Lester]:    North, south, east, west, wherever there were liquor stores to turn over and hitchhikers to disappear.
[Extreme][Michael]:    Where did they bury him?
[Extreme][Lester]:    They buried him? Not as far as I know.
[Extreme][Michael]:    He's probably a John Doe then, right? What do you think? OD? Shootout? Maybe just a car crash, right?
[Normal][Lester]:    I saw a ladder. Climb up and see if you can get to the roof.
[Extreme][Michael]:    I'm on the roof.
  One line split into 2:
[Easy][Lester]:    Alright, use the glasses to get a shot of Vangelico's roof unit. It'll be right above the store. 
[Hard][Lester]:    I've pulled up a satellite image. It looks like the highest point is on the north west side. Get a shot from there.
[Normal][Lester]:    Right, you're well placed to take the photo of the system now. Okay, capture an image of the system and we're done.
[Easy][Lester]:    We've got our shot of the Vangelico unit, looks good. Okay, that'll do. Now, come back to me before someone spots you up there.

Michael goes back to the car and drives back to the garment factory.
[Hard][Michael]:    Here, take your glasses back.
[Normal][Lester]:    Let's go back to the garment factory, I called ahead and told them to start setting up the information.
[Extreme][Lester]:    Nothing that'll cause undue complications.
  One line split into 2:
[Normal][Michael]:    Yeah, it looked like a simple set-up: cameras broadcasting to a remote server. We might be able to wipe 'em remotely. 
[Hard][Michael]:    Security guard on the door: he won't want to die for rich assholes that rub his nose in it.
[Normal][Lester]:    Good. The alarm system's linked to the door lock. We'll get a good window if someone talented hacks it.
  One line split into 2:
[Normal][Lester]:    Well, the, uhh, more valuable merchandise is in the cabinets in the center of the store by the register. so I'd start there. 
[Easy][Lester]:    Umm... Glass in the cabinets wasn't bulletproof, means you can smash 'em easy enough, but the stones'll be in the safe at night.
[Normal][Michael]:    So, we go in when it's open, then?
[Normal][Lester]:    Right. Once we melt down the gold, re-cut the rocks, that's an okay score.
[Normal][Michael]:    Yeah, shame we can't go in after hours, man. Those vents looked promising.
[Extreme][Lester]:    Might be able to flip that another way.
[Easy][Michael]:    There's this kid who's been helping me. Maybe we could cut him in.
[Extreme][Lester]:    I don't work with amateurs.
[Normal][Michael]:    He ain't an amateur. Or, if he is, he's a gifted amateur about to turn pro. He's a good kid, Lester.
[Hard][Lester]:    You know what they say, it's your funeral, one of them, at least.
 
Michael and Lester head into the office.
[Hard][Lester]:    My workers have their uses. Okay, let me set this up.
[Normal][Michael]:    Nice to see the methods haven't changed.
  One line split into 2:
[Normal][Lester]:    Well...we gotta figure out what we're doing somehow, all the crews, the roles, prep work.
[Hard][Lester]:    Don't want to leave evidence behind on a hard drive. So, yeah, the er...methods don't change.
[Extreme][Michael]:    Right, not for a pro.
  One line split into 2:
[Normal][Lester]:    Well, mapping out the options and showing you all the angles, that's my area of professional expertise.
[Hard][Lester]:    But making decisions, that is your domain, my friend. Here.
  One line split into 11:
[Easy][Lester]:    There's two ways I see of doing this - we go in smart, or we go in loud and dumb.
[Easy][Lester]:    Remember the vents? If we're gonna be smart, we pump a little knockout gas through the air system, then hit the cabinets while everyone's out.
[Easy][Lester]:    You'll have to source the gas, of course, but crowd control won't slow you down, and that might improve the take.
[Normal][Lester]:    The cover is pest control, so no one will look twice when you're wearing gas masks, that means getting a pest control van, though.
[Normal][Lester]:    You go in dumb and you'll need your famous way with people and four carbine rifles.
[Hard][Lester]:    We can't buy 'em and risk 'em getting traced. No no no, we gotta find some in circulation.
[Normal][Lester]:    It's awkward, it's real awkward, but this is the gun favored by LSPD tactical teams, so one of their vans is probably a good place to look.
[Easy][Lester]:    A hacker can disable the cameras, the length of time depends on their ability. The alarm will be operating on the same window.
[Easy][Lester]:    The exit strategy is more or less the same for both options: the driver you pick will, of course, source some bikes.
[Easy][Lester]:    You come out of the store, and make your way through the new subway tunnel they're digging off the Del Perro Freeway.
[Easy][Lester]:    You lose the cops in there and meet a truck in the LS River.
[Easy][Michael]:    Alright, I want my guy, Franklin, on the getaway. He can handle a bike.
  One line split into 2:
[Normal][Lester]:    Alright, if you vouch for him, I'll take the risk.
[Easy][Lester]:    So, how do you wanna do this? Run in through the front door, or try to play it smart?

-Loud approach
[Normal][Lester]:    Ah, still a hothead? Some things never change. Select personnel with that in mind.

-Smart arroach
[Normal][Lester]:    Ah, you've grown wise and cautious in your age. Okay. Select personnel with that in mind.

[Normal][Lester]:    As ever, the better they are, the bigger the cut. 
[Normal][Lester]:    Now, the driver, they'll source the bikes, lead you out through the tunnels.

-If Eddie Toh
[Hard][Lester]:    Eddie Toh. Well, you can count on him to get you out of a spot.
-If Karim Denz
[Hard][Lester]:    Ah, okay. This one's new blood. I've seen him drive, but I haven't seen him under pressure.

-Loud approach
[Normal][Lester]:    Guns. It might be hot and heavy in there, this guy'll keep it from going bad.
-Smart arroach
[Normal][Lester]:    Guns. We're hoping to keep quiet, so this guy shouldn't make much difference.
 
-If Gustavo Mota
[Hard][Lester]:    Gus Mota. He's a pro, not much else to say.
-If Norm Richards
[Hard][Lester]:    Ah, Norm, came across as a bit of an idiot, but could be useful.
-If Patrick McReary
[Hard][Lester]:    McReary? He was part of a well-known Liberty City stick-up crew. Small world.

[Normal][Lester]:    Hacker. Back office, but this is the person who will determine how long you'll get inside.

-If Paige Harris
[Hard][Lester]:    Harris. Good. Feminine touch. She'll be able to find any back doors they got.
-If Christian Feltz
[Hard][Lester]:    Feltz. Okay, he's not the best, but if you move fast, that won't matter.
-If Rickie Lukens
[Hard][Michael]:    This guy - Rickie. I met him at the Lifeinvader office. He may not be that good, but he's enthusiastic.
[Extreme][Michael]:    Let's take a chance on him.
 
Lester confirms the plans.
[Hard][Lester]:    If you're happy, I'll start making the arrangements.
[Hard][Lester]:    That look good to you? Are you sure?
[Hard][Lester]:    If this is how you want to do it, I'll get moving.
 
The player confirms their choices.
[Normal][Lester]:    Great, I'll do some research on a pest control van and the knockout gas, and I'll be in touch.
[Normal][Lester]:    Ah yes, good...good. I'll call you when everything's ready. You'll need to pitch it to the guys.
[Normal][Michael]:    Whoa, what, my rep don't count for nothing no more?
[Normal][Lester]:    You're a dead man, Michael. I'll call you.
 
After the mission, Michael calls Franklin.
  One line split into 2:
[Normal][Michael]:    Listen...err...I gotta get hold of the money for that house we pulled down, so, well, I'm getting a crew together for...you can guess.
[Hard][Michael]:    The pay'll be awful, and the risk'll be high, but you might learn something, if you're interested.
[Hard][Franklin]:    Man, that's not exactly a great sales pitch, dog, but I guess I gotta start somewhere.
  One line split into 2:
[Hard][Michael]:    Thank you. Maybe one day you can put together your own deals, your own... jobs.
[Normal][Michael]:    So, there's still some preparation I gotta do, sit tight for a while, my buddy Lester will get in touch with the details.
 
-Franklin can call Lamar afterwards.
[Extreme][Lamar]:    You calmed down since that recycling job, dude?
[Extreme][Franklin]:    Yeah, I'm calm. Since I'm dealing with professionals instead of you clowns.
[Extreme][Lamar]:    You's a professional pain in the ass. At least Stretch out now, and I ain't got to run with you suckers no more.
[Extreme][Franklin]:    Well shit, good luck. You fools need it.
)"},
    {"Chop", R"(
Franklin arrives at his house and hides as Denise prepares to leave
[Normal][Denise]:    Girl, of course I saved that poor boy's life. But you know what? It's getting to be a bit much.
[Normal][Denise]:    'Course I cope. I'm a woman.
[Normal][Denise]:    But, girl, I done done all that I can do, but you know how boys are.
[Normal][Denise]:    Wait a minute... Oh, girl... Oh, hey, how much further?

Denise and her friend start walking down the sidewalk
[Hard][Denise]:    We are women...
[Easy][Denise]:    We are women, hear our pain, we are women, hear our shout, and we are women, have no doubt.

Franklin walks to the front door as Lamar shows up with Chop
[Easy][Lamar]:    Damn, F is that your auntie?
[Easy][Franklin]:    Yeah, thank God I missed her crazy ass. She spirit walking and shit now, man... that's just her attempts to...
[Easy][Lamar]:    Hey, hey! Don't be talking shit about your auntie, man, she got... I mean she cool as a motherfucker, man, come on.
[Normal][Lamar]:    We gotta go pick up some shit from round the corner, man. We can walk and talk at the same time, my nigga.
[Normal][Franklin]:    Why the fuck we can't drive?
[Easy][Lamar]:    Around the block? With Chop? You need to walk with your fat ass.
[Normal][Franklin]:    Yeah, okay, you tall, lanky son of a bitch.

The two are walking towards the van
[Hard][Lamar]:    Come on, homie, we ain't got all day, let's go.
[Normal][Franklin]:    Fo' sho, but what you got up?
[Easy][Lamar]:    Kidnapping, fool. That clown D, that OG fool from Ballas.
[Easy][Franklin]:    Dog, I told you; no more gangbanging, retro-vengeance bullshit. I'm trying to make some fucking paper.
[Normal][Lamar]:    You gonna make some paper, loc. And ain't nobody out here gangbanging, it just looks like that. You gotta know the difference, man.
[Normal][Franklin]:    Fuck, man, great. My aunt will be very happy, homie. She wants me dead anyway so she can get the fucking house.
[Normal][Lamar]:    I told you to quit talking shit about your auntie, loco. That's my bitch. I'm just fucking with ya...I'm just fucking with ya.

-If Franklin doesn't follow Lamar
[Extreme][Lamar]:    Man, there's two homies right here waiting on your ass
[Extreme][Lamar]:    Do I need to put a leash on your ass? Come on, let's go, dog.
[Extreme][Lamar]:    Man, you always was the easily distracted motherfucker.
[Extreme][Lamar]:    Come on, homie. You worse than Chop.

Franklin and Lamar arrive at a van parked in an alley
[Normal][Lamar]:    You driving.
[Normal][Lamar]:    You got the wheel, homie.
[Easy][Lamar]:    Get in the van, Chop. Get in the van. Good dog.
[Normal][Lamar]:    We goin' up Vinewood Boulevard.

-If you completed Father/Son before
[Easy][Franklin]:    I like your dog, homie. Me and Chop got a lot in common - your annoying ass.
[Normal][Lamar]:    Man, I'm carrying both of y'all asses homie. Look what I set up.
[Normal][Franklin]:    Man, fuck this, man - you seen Tanisha?
[Hard][Lamar]:    She straight. It's me and you that ain't straight though, homie.
  One line split into 2:
[Easy][Franklin]:    Dog, I know, homie. But look, I met this contact, this white dude. Real serious dude, man. 
[Hard][Franklin]:    This motherfucker knows the streets. homie. I know he'd be a good hookup for us.
[Hard][Lamar]:    We don't need no hookup, fool. I know these streets.
  One line split into 2:
[Hard][Franklin]:    You? Know these streets? Man, all you know is dime bag hustling, credit card stealing. 
[Hard][Franklin]:    Boosting gas tankers, homie, come on man. You trying to be some fucking commodity trader or something?
[Extreme][Lamar]:    Fool, that shit went up, man.
[Hard][Franklin]:    Look homie, I don't mind dying. You feel me? But I just want to die with something that matters, homie. That's what Forum gangsters should be really about.
[Normal][Lamar]:    And I know this much, the motherfucking OGs ain't even giving a fuck about us, though.
[Normal][Franklin]:    Man, fuck the OGs then. You know what I'm saying? This ain't no motherfucking pyramid scheme.
  One line split into 2:
[Hard][Lamar]:    Wait, hold on. Listen to your boy one time. Listen to your boy. You want some paper, my nigga?
[Normal][Lamar]:    This is what it's about. Check it out. I'm talking about forty thousand. No problem. Cash in hand. Two days time, no killing. Nothing.
[Normal][Franklin]:    Nah, just starting another beef with the fucking Ballas, nigga, that's class-A felony bullshit.
[Hard][Lamar]:    We gonna keep our disguise on. Ain't nobody gotta know it was us.
[Hard][Franklin]:    Man, what a long way we've come, homie.
[Normal][Lamar]:    Fuck you want to go a long way for? We right here, right now, loco.
[Hard][Franklin]:    That's cool if you want to be bending corners on coke and cough syrup all your days.
[Extreme][Lamar]:    I seen you on that shit before.
[Hard][Franklin]:    There you go. Maybe you have. But shit has got to get serious, man. Forum gangsters is about real shit.
[Normal][Lamar]:    You think running repos for them Armenian fraudsters was serious? Man, please.
[Hard][Franklin]:    Nah. That why I didn't come at your ass for fucking shit up.
[Normal][Lamar]:    I fucked it up? Man, you the genius that crashed through the dude's window.
[Normal][Franklin]:    Man, one - I had a gun to my fucking head. Two - You the one fucked with them eses, man.
[Extreme][Lamar]:    When you met a man who could tell you what to do?
[Normal][Franklin]:    Like I said, this dude is serious. Creeped on me like some stealth shit.
[Hard][Lamar]:    Fool, you slippin'.
[Hard][Franklin]:    You don't wanna fuck with this man, dog, even you.
[Extreme][Lamar]:    Man, I don't give a fuck.
[Hard][Franklin]:    Yeah, your ass keep saying that.
[Hard][Lamar]:    Man, I don't even know what you trippin' on.

-If you didn't complete Father/Son before
[Normal][Franklin]:    Man, what the fuck Chop do to deserve a fool like you?
[Normal][Lamar]:    Chop lucky, homie. Ain't you, Chop? Ain't you, boy?
[Hard][Franklin]:    Poor dog, man, he don't know what the fuck you sayin'.
[Normal][Lamar]:    Oh, you wouldn't understand that shit. Us Apache - we got a bond with the animal kingdom.
  One line split into 2:
[Hard][Franklin]:    Yeah, you do got a bond, nigga. I seen you bonding with plenty of animal-type bitches. 
[Hard][Franklin]:    I'm talking big-ass, hairy, scary bitches. It's true about you Apache motherfuckers, y'all do got a bond.
[Extreme][Lamar]:    Fuck you, homie. A little mustache ain't shit. That's just a sign of virility.
[Extreme][Franklin]:    Maybe in the dog world, nigga. What you think, Chop? Come on boy, what you think? You like a little hair on your lips, puppy?
[Hard][Lamar]:    Least I know what I can get. You still after the same bitch from high school. Only she ain't interested in some of your...uh...life choices.
[Hard][Franklin]:    Nigga, you the life choices she don't like, nigga.
[Hard][Lamar]:    Nah, nigga, we cool, man. She kick it with me more than you do. Tells me about the lawyer, nuclear physicist, humanitarian, super nigga she fucking.
[Hard][Franklin]:    Nigga, shut the fuck up with that shit. I'm done, nigga. I moved on many a times, nigga.
[Normal][Lamar]:    Oh, whatever nigga, that's cool. But on some other shit though, you heard the boy Stretch gettin' out, huh?
  One line split into 2:
[Extreme][Franklin]:    He gettin' out? Then the State is in some real motherfucking trouble, nigga. 
[Extreme][Franklin]:    I didn't think no amount of over-crowding would put that nigga back on the streets, dog.
[Extreme][Lamar]:    Budgetary realignment, homie. They aligning the homie right up outta Bolingbroke.
[Extreme][Franklin]:    Damn! Well, let's just hope he don't fall back into that same downward spiral that put him in to begin with, nigga.
[Normal][Lamar]:    You fucking with me, right?
[Hard][Franklin]:    Yeah, I'm fuckin' with you, dog.
[Hard][Lamar]:    Going to snatch a fool, acting all judgmental and shit. Look at you man, that shit is lame.
[Normal][Franklin]:    Eh, why we doing this, dog?
[Normal][Lamar]:    Man, 'cause we supplementing our income.
[Normal][Franklin]:    More like supplementing the drama in our lives.
[Normal][Lamar]:    Is that fool Simeon looking out for us? Or is he looking out for hisself?
[Hard][Lamar]:    So, how a couple of gutter-ass fools like us get ahead?
[Hard][Franklin]:    By getting serious.
[Hard][Lamar]:    Exactly. We two highly motivated, results-driven motherfuckers with an entrepreneurial mindset.
[Normal][Franklin]:    Oh, yeah, yeah. Highly motivated self-starters, huh? In the kidnapping sector.
[Extreme][Lamar]:    Yeah. Starting big.
[Hard][Franklin]:    But it always go wrong, don't it? All your schemes, for years.
[Hard][Lamar]:    They don't go right, but I wouldn't say that they go wrong all the time, neither. Not as wrong as they could.
[Hard][Franklin]:    I ain't dead but I ain't rich neither.
[Normal][Lamar]:    How does forty thousand sound? 'Cause that's what happening right here.
[Hard][Franklin]:    Man, I'll believe it when I'm holding it.
[Easy][Lamar]:    Three way split, homie. Me, you, and Chop.
[Normal][Franklin]:    Man, Chop don't get shit. Chop a intern.
[Normal][Lamar]:    You hear that, Chop? Man, Frank tryin' to screw you.

-If Chop barks
[Hard][Lamar]:    Chop a free spirit. He bark all he likes.

The two arrive at Vinewood Boulevard
[Normal][Lamar]:    He down this alley up here.
[Normal][Lamar]:    I been told he up in the alley.

D is talking to a girl in the alley
[Normal][D]:    Hey what's up, boo? Ain't you little Laita's cousin?
[Normal][D]:    Damn, you short with it? I was just saying, I was trying to holla at you.
[Normal][D]:    Why is it gotta be like that? I'm a OG...
[Normal][Girl]:    An OG, so what? So the fuck what, nigga? S'million OG's around here.
[Normal][D]:    Well shit, how about I put one of these little X pills up your ass crack? Next thing you know you gonna be begging for it, boo boo.

Franklin and Lamar confront D
[Easy][Lamar]:    What's happening now, D man? Ain't no fun if the gangsters can't have none.
[Normal][D]:    Man, fuck you, mark. I ain't sharing no ass with the CGFs.
[Extreme][D]:    Man, shut the hell up, bitch!
[Normal][D]:    Man, fuck y'all. Hey, ain't there a law against you mark-ass gangstas, insignia-mask-wearing motherfuckers?

Lamar pulls out a pistol
[Normal][Lamar]:    Oh, so what's up now, nigga? You snitchin' or somethin', nigga?
[Extreme][Lamar]:    Bitch-ass nigga.
[Normal][D]:    Fuck you, nigga. I'm outta here!

D speeds away on his bike
[Extreme][D]:    Fuck y'all, bitch!
[Easy][Lamar]:    Hey, come and get that nigga. Come on, let's go. Go! Go! Get in the van!
[Easy][Franklin]:    You see what he's driving? Man, we in a van, motherfucker. We fucked!
[Hard][Lamar]:    Oh, gangster. We got this.
[Hard][Franklin]:    Hold on, Chop.

-If D is getting away
[Hard][Lamar]:    He leaving us behind, fool.

-If the player bumps into something.
[Hard][Franklin]:    You okay, Chop?

-If D is getting away
[Normal][Lamar]:    OG's gettin' away!
[Normal][Franklin]:    What the fuck you say something for? We could have creeped up on this nigga.
[Easy][Lamar]:    You seen yourself, Franklin? You is a big black motherfucker, nigga. You creepin' days is over.
[Normal][Lamar]:    Do that weird, like, focus shit you do. That's forty Gs gettin' away right there.
[Extreme][Lamar]:    I should have took the wheel.
[Normal][Franklin]:    Like you coulda done better. This piece of shit ain't going no faster!

-If Franklin uses his special ability
[Hard][Lamar]:    You get all sex face when you do that, homie. That's hilarious.

-If chase continues
  One line split into 2:
[Normal][Franklin]:    We in a van, nigga. This motherfucker is slow as hell! Next time we goin' after a motherfucker in a car, alright? 
[Hard][Franklin]:    All these punk-ass bikes. If we snatching this dude, we snatching his ass right. Remember the homies around the block?
[Extreme][Lamar]:    Man, the homies is lame.
  One line split into 2:
[Hard][Franklin]:    Yeah, so we not. Cops were on their cellphone soon as they made the ransom call. 
[Hard][Franklin]:    Triangulated the signal. Ghetto birds all over the place. Surveillance, my nigga.

D crashes on his bike
[Easy][Lamar]:    Damn, he got fucked up! Man, take Chop, go get that fool!
[Normal][Franklin]:    Nigga, you just sit on your ass there with your feet kicked up!

Franklin lets Chop out of the van
[Easy][Franklin]:    Come on, Chop, come on, go bite his ass, get that motherfucker, Chop!
[Hard][Franklin]:    The ransom's still the same if you got a bite taken out your ass.
[Normal][Franklin]:    How the fuck you end up with your dumb ass owner, man? And how the fuck did I?

[Hard][Franklin]:    I don't wanna watch you get eaten by this canine, punk. Let's do this, Chop Chop.
[Hard][Franklin]:    Least I'm getting a workout. I thought you was an original gangster. You just a motherfucking chump. This like sprint training.
[Hard][Franklin]:    Get him, boy! Take him down, homie!

D hops on a leaving train
[Easy][Franklin]:    Aw, fuck! Come on, boy. Find that fool. Sniff him out, Chop Chop. Lead me to him.
[Easy][Franklin]:    He hiding in that train, boy.

Franklin opens the boxcars
[Extreme][Franklin]:    Shit, this motherfucker empty.
[Hard][Franklin]:    Yo' ass caught! Lay down, bitch!
[Normal][Franklin]:    Where is he, boy? Come on, where is he?
[Easy][Franklin]:    You got a whiff of him, Chop?
[Normal][Franklin]:    We in this together, Chop. Let's go.

Chop senses another nearby dog
[Normal][Franklin]:    Hey, where you going, boy? That don't look like no Ballas OG to me. Chop! No! Down, boy!
[Easy][Franklin]:    Shit, Chop. Man, that's a dude, dog. Your little nasty ass ain't picky, is you? 
[Easy][Franklin]:    Come on, Chop. Get off there, man. We got shit to do. Man, that's a dude, Chop. You'll fuck anything. Get out that thing, Chop, you filthy motherfucker.
[Normal][Franklin]:    Not the time, Chop. We got to go. 
[Easy][Franklin]:    This ain't time for humpin', Chop. Come on, man.
[Hard][Franklin]:    Come on, you horny little motherfucker. You need boot camp or some shit.
[Easy][Franklin]:    Get back on that fat motherfucker, Chop! Eh, Chop. That smell like a Balla? You smell that motherfucker, boy? 
[Hard][Franklin]:    Go boy! Where that OG at?

Chop singles out one boxcar, which Franklin opens
[Normal][Franklin]:    Come on, Chop. Come on boy. You a mean motherfucker, man. Let's go.
[Hard][Franklin]:    Stop running, dog!
[Easy][Franklin]:    You scared of dogs, nigga?
[Easy][D]:    Oh, shit! Screw that dog, man.
[Easy][D]:    Fuck you and your stupid dog.
[Easy][Franklin]:    Don't hump him, bite his ass, Chop. Get his ass.

Chop catches up to D and takes him down
[Hard][D]:    Get off me! Fuck you, son of a bitch!
[Extreme][Franklin]:    Good boy, good boy.
[Normal][D]:    That bitch just fucking bit me, man!

Lamar arrives with the van
[Easy][D]:    Oh, shit, what the fuck, man, I ain't got no beef with the CGF.
[Normal][Franklin]:    'Cause maybe we doing our own thing.
[Normal][Lamar]:    Get the fuck in the van, punk!
[Easy][D]:    Shit! Hey, Lamar, is that you, nigga?
[Hard][Lamar]:    Nigga, shut the fuck up, just get in.
[Hard][D]:    Yeah that's you, nigga...
[Hard][D]:    I said I had no beef, man.
[Extreme][Franklin]:    Watch him, boy.
[Normal][D]:    Keep this fucking dog away from me!

They drive away from the railyard
[Hard][Franklin]:    Hey, if you don't train Chop, he goin' be a lost cause like you.
[Normal][Lamar]:    We gonna stash this dude at my spot.
[Normal][D]:    We going back to your crib? I been there when you was in diapers.
[Normal][Lamar]:    Shut up, man. You ain't recognize me.
[Easy][D]:    I knew it was you before you took that flag off. You always been dumb, Lamar.
[Normal][Lamar]:    Really? Well, I guess that mean we gonna have to shoot yo' ass when we pick up our forty stacks.
[Normal][D]:    You ain't gonna pick up shit. Feds gonna be on you before you can even move, nigga.
[Normal][Lamar]:    Be quiet. I gotta make a call.
[Normal][Lamar]:    We got your boy.
[Hard][Franklin]:    You calling them on a cellphone, you dumb motherfucker? They going to trace this shit in a sec!
[Hard][Lamar]:    We want forty thousand. It's pay me or pay the funeral director, motherfucker.
[Normal][Franklin]:    What the fuck you gone done? You just gave them our location. Now we gotta let this motherfucker outta here.

-Alternative dialogue
[Hard][Franklin]:    Why the fuck you pull your flag down?
[Extreme][Lamar]:    Man, needed to breathe.
[Easy][D]:    Lamar motherfucking Davis. This just the kind of lame-ass shit marks like you try to pull.
[Normal][Lamar]:    Man, fuck you. And who the fuck is this Lamar nigga?
  One line split into 2:
[Hard][Lamar]:    We gonna see who lame when they got my two in the back of the head and little Chop Chop chewing on their shit. 
[Normal][Lamar]:    I'ma make some bills off this fool. Just shut up while I make the call.
[Normal][Lamar]:    Yeah, we got your homeboy, and we ain't trippin'. We goin' smoke his ass if you don't come with that bread.
[Normal][Franklin]:    This shit dumb. They going to be all over your fuckin' cellphone.
[Normal][Lamar]:    Forty thousand, motherfuckers. Or this nigga goin' be in forty little pieces.
[Normal][Franklin]:    What the fuck, homie? Half the city going to be mobilized on this shit! We got to drop his ass!

Franklin stops and lets D out
[Normal][Franklin]:    Get the fuck outta here. And, gimme that damn phone.
[Normal][D]:    Fuck y'all. I be seein' y'all soon...
[Normal][Franklin]:    Nigga, the only reason you been seein' shit 'cause we went easy on your ass. Remember that, dog!
[Normal][D]:    And you owe me a bike too, you motherfuckers!
[Hard][Lamar]:    This some bullshit. Take me down the cut.

Franklin drives to the recreational center
[Hard][Franklin]:    Man, what the fuck is wrong with you, nigga?
[Normal][Lamar]:    I was getting us paid. What the fuck is wrong with you, nigga? That was a good phone.
[Hard][Franklin]:    A good phone? The cops was all over, nigga.
[Hard][Lamar]:    I coulda swallowed my card. Try to triangule that.
[Extreme][Franklin]:    It's too late. Shit's done. Least I saved you the indignity of pullin' apart your shit.
[Extreme][Lamar]:    Nigga, I ain't afraid to get my hands dirty. Ol' precious motherfucker.
[Hard][Franklin]:    This is what I mean, homie. We need to get serious. Get paid. This shit ain't working.
[Hard][Lamar]:    So your old white dude's gonna fix us. Where's my first class?
[Hard][Franklin]:    Look, I'ma learn some skills, man. Pass 'em on. There's a whole city out there. It's waiting to be taken, nigga.
[Hard][Lamar]:    You just give me the heads up when you over that shit, nigga. Ready to wipe old due nut off your face. Ol' lame-ass mark!

They arrive at the recreational center
[Normal][Franklin]:    You the motherfucker. You'd better watch out for them Ballas, they gonna be on you now. Them cops gonna be on your ass too.
[Easy][Lamar]:    Yeah, I ain't worried about it. I'm a motherfucking gangster, you know how I do. I can take care of my sizelf.
[Easy][Franklin]:    No the fuck you cizain't.
)"},
    {"Complications", R"(
Franklin arrives at the showroom
[Easy][Simeon]:    You're a racist.
[Easy][Simeon]:    You don't like me because you think that I am an Arab.
[Hard][Mr._Kenneth]:    What? No! What are you talking about? It's nothing like that, wait!
[Easy][Simeon]:    Excuse me. That boy, I am his mentor. I am so proud of you.
[Normal][Franklin]:    What do you mean, a mentor?
[Hard][Simeon]:    Don't worry about that.
[Hard][Franklin]:    Okay, so what you got for me?
  One line split into 4:
[Easy][Simeon]:    James De Santa. Some kid, he is already late on his payments and I have this bad feeling that he will do more damage to the car than we can get back from him in the exorbitant interest rate payments. 
[Easy][Simeon]:    Just go and get it. The house is on... Hampstead, off Eclipse. It's an SUV. 
[Normal][Simeon]:    Some Rockford Hills daddy's boy nonsense. 
[Easy][Simeon]:    Don't worry about it, try to bring the car back in good condition, huh?
[Extreme][Franklin]:    I gotcha, don't worry about it.
[Normal][Simeon]:    It's so good to see you, my boy! Good luck in... law school!
[Normal][Simeon]:    So, Mr. Kenneth, were we at financing?

-If Franklin stays to listen to Simeon and Mr Kenneth
[Hard][Mr._Kenneth]:    The financing - it... it seems like a shitty deal.
[Hard][Simeon]:    Because of the color of my skin, you think I am a scammer?
[Hard][Mr._Kenneth]:    No, no... skin color's got nothing to do with it. My credit's okay, and this is all like high-risk financing...
[Hard][Simeon]:    Yes. You are a risk. I will not give my stock away just because you are a white man.
[Hard][Mr._Kenneth]:    No, I want a fair deal because I'm a responsible borrower in long term employment... Can you let me think about it?
[Hard][Simeon]:    What's to think about? You're either a man or you're a vagina.
[Extreme][Mr._Kenneth]:    It just doesn't feel right.
[Hard][Simeon]:    You do not feel right. Perhaps a rich idiot like you can waste the day, but I have children to feed. Decide.
[Hard][Mr._Kenneth]:    I've got to be sure this is the right decision.
[Extreme][Simeon]:    You're wasting my time.
[Extreme][Mr._Kenneth]:    Gimme a minute.
[Hard][Simeon]:    All this time, I could be mentoring the disadvantaged.
[Extreme][Mr._Kenneth]:    Look, I'm thinking.
[Hard][Simeon]:    Buy the car, or get off the floor.
[Hard][Mr._Kenneth]:    Can't you speak to another customer and come back to me?

-If Franklin doesn't leave Simeon
[Hard][Simeon]:    Rockford Hills. The yellow four-by-four.
[Hard][Simeon]:    This is under control. Get the car, okay?
[Hard][Simeon]:    I've got this covered. Go and get the car.

Franklin leaves and soon receives a call from Simeon
[Hard][Franklin]:    Eh, did you change your mind?
  One line split into 2:
[Normal][Simeon]:    When I discover that you betray me, perhaps. 
[Easy][Simeon]:    I hear you took the bike for yourself, my Employee of the Month!
[Easy][Franklin]:    Listen, man, me and Lamar was gonna get that back to you, dog.
  One line split into 2:
[Easy][Simeon]:    Oh, I am sure! You will get this car off the daddy's boy, and then we talk. 
[Easy][Simeon]:    Insurance papers say they have a locked garage, so you'll need to gain access from inside the house.
[Easy][Franklin]:    Man, it's never easy with you, is it, Simeon?
[Easy][Simeon]:    Do not talk to me about easy, you thief!

Franklin sneaks into the michaels house
[Easy][Jimmy]:    Just 'cause you got a massive gaper, bitch.
[Easy][Tracey]:    You fucking homo. You're dead! Dad, he said I had a massive... Jimmy called me a bitch!

-Optional dialogue from Tracey
  One line split into 7:
[Easy][Tracey]:    Oh my god, seriously, my brother is such a homo. 
[Hard][Tracey]:    I think he has a medical problem. Like, more medical problems than the ones he's already been diagnosed with. Mental ones. 
[Hard][Tracey]:    Seriously, penises are not meant to be that small. I'd fucking know, right? I've seen enough of them. 
[Hard][Tracey]:    It's probably 'cause he's so fat. I still love him though. Sort of. 
[Hard][Tracey]:    Well, the other day, I walked in on him, and he was jerking off over pictures of my friends. 
[Hard][Tracey]:    No, not you! The hot ones - Lauren and Lisa. No, I didn't mean it like that. You're beautiful! And interesting! 
[Hard][Tracey]:    It's just that, you know, guys don't... they just don't get you. Hello? Hello?! Fuck... Whatever, bitch.

[Easy][Jimmy]:    He tried to knife-attack me? No one creeps on the J-dog, my niggas!

-Optional dialogue from Jimmy
[Hard][Jimmy]:    I don't care if you're twelve, I'll still rape you.
[Hard][Jimmy]:    Oooh, ouch. Rape-a-rino!
[Hard][Jimmy]:    LOL, you suck fat man's dick.
[Hard][Jimmy]:    Get off my face, you fucking homo!
[Hard][Jimmy]:    You're a waste of semen, bitch!
[Hard][Jimmy]:    Dead, you fucking idiot.
[Hard][Jimmy]:    Oooh, slaughter time!
[Hard][Jimmy]:    I'll cut your dick off if you call the administrator. Hey, you know what? I am the administrator!

[Normal][Amanda]:    Thank you, coach.

-Optional dialogue from Amanda and Kyle (Tennis coach)
[Easy][Kyle]:    You're a real pro, Mrs. De Santa. A real pro. Well, you're a great student. Now just loosen up those hips.
[Extreme]Amanda:    Okay. Like this?
[Hard][Kyle]:    Yeah, loosen them up. There you go. And follow through. Perfect.
[Extreme][Amanda]:    Ohh, okay. I think I'm getting it.
[Easy][Kyle]:    Ohhh, okay, Amanda. Now, just follow through. God, you've got great hips, you know that? Follow through.
[Extreme][Amanda]:    Yeah, I could get used to this.
[Hard][Kyle]:    Excellent. Yes! Now slide your hips slow and sit into it right here. No, right here.
[Hard][Amanda]:    Oh yeah... I could totally get used to this!

-If Franklin is spotted
[Hard][Jimmy]:    Holy fucking shit, bro! Dad! Dad, there's a dude! Dad, help! Dad!
[Hard][Tracey]:    Who the fuck are you? Dad! Ahhhh! Dad! Ahhhhh!
[Extreme][Amanda]:    Ahhh! Who the fuck are you?
[Extreme][Kyle]:    Can I help you?
[Extreme][Amanda]:    Do something! Fucking do something!
[Hard][Kyle]:    Help! He's...he's black! Heeeelp!

Franklin sneaks into the garage and calls Simeon
[Easy][Franklin]:    Eh, Simeon. I got the ride, man, I'm coming back.
[Easy][Simeon]:    If you actually bring the repossession to me this time, I can have it back out on the street before the day is done.
[Easy][Michael]:    That's a nine millimeter semi-automatic pushed against your skull.

-If Franklin has already left the house
[Easy][Michael]:    Ah, don't look around. You just keep driving where you're going.
If Franklin hasn't left the house yet
[Normal][Michael]:    Don't look around. Take me where you're going.

-If Franklin stops the car
[Hard][Michael]:    I said drive!
[Hard][Michael]:    What, you need some motivation? Drive!
[Hard][Michael]:    Take me where you were going!

[Easy][Franklin]:    Hey, come on, man, this was a repo job. Guy was behind on his fuckin' note.
[Easy][Michael]:    Unlikely, considering my son just got the car. And looking at the way you're going about this, my guess, you're working a credit fraud.
[Easy][Franklin]:    A credit fraud? Be serious, dude, I just work the fuckin' repos.
[Easy][Michael]:    I appreciate a kid who follows orders without taking responsibility. Yeah, maybe one day we'll have a beer, and I'll explain how the world really works. Who gives you the slip?
[Easy][Franklin]:    A car dealer, dog, by the name of Simeon Yetarian.
[Easy][Michael]:    So this businessman, he look legit to you?
[Easy][Franklin]:    Look, man, it's just between him and your fucking son.
[Easy][Michael]:    Don't worry. Me and Mr. Yetarian, we'll work this out.

-If Franklin doesn't take Michael to the dealership
[Hard][Michael]:    This don't look like the way to no-credit alley to me.
[Hard][Franklin]:    Shit, man, with traffic and all, this way is faster.
[Hard][Michael]:    Dumb move, kid.
[Hard][Michael]:    You just got a little bit dumber.

Franklin reaches the showroom.
[Hard][Franklin]:    Hey, man, it's just up here.
[Normal][Michael]:    Okay. Stop the car. Pull up.

Franklin stops the car
[Hard][Michael]:    That the place?
[Normal][Franklin]:    Yeah, that's the place, man. Whoa.
[Easy][Michael]:    Drive into it. Right through the fucking window, and fast. Or I'll put two rounds in the back of your skull, and do it myself.
[Hard][Franklin]:    Man, you can't be for real?
[Normal][Michael]:    I look like a fucking joke to you?
[Normal][Franklin]:    Man... Fuck my life, man. Fuck it.

Franklin starts driving
[Normal][Michael]:    Ram it already!
[Hard][Michael]:    I still got this gun to your head!

Franklin drives into the showroom through the window
[Hard][Franklin]:    Shiiiiit!
[Normal][Franklin]:    Shitty situations, dog.
[Easy][Simeon]:    Franklin! What the fuck are you doing?
[Easy][Franklin]:    Mr. Simeon, it's not exactly how it looks.
[Normal][Michael]:    I always trump big for a job well done. Now get out of here, kid.

Michael fights Simeon
[Extreme][Simeon]:    You motherfucker!
[Easy][Simeon]:    Simeon Yetarian doesn't back down from anybody!
[Hard][Simeon]:    See, now, you've pissed me off!
[Normal][Simeon]:    I won't be treated like this!
[Easy][Michael]:    You recognize this car? Huh? Does it look like it's worth five grand a month to you?
[Hard][Simeon]:    You fucking racist...
[Easy][Michael]:    I'll tell ya something, this thing's gonna need some serious bodywork before it's worth five grand a month!
[Normal][Simeon]:    He agreed to financing, I have his signature.
[Easy][Michael]:    Yeah? Did he agree to have some punk break into my fucking house?
[Extreme][Simeon]:    I- I don't know...
[Easy][Michael]:    That kid might be a fucking idiot, but you are a fraudulent scumbag piece of shit.
[Easy][Michael]:    Don't make me have to come back here.

-Optional post-mission phone calls
-Michael calls Dave Norton
[Hard][Dave]:    Michael.
[Hard][Michael]:    Dave.
[Extreme][Dave]:    To what do I owe you this pleasure?
[Extreme][Michael]:    Just want to talk.
[Extreme][Dave]:    You behaving yourself?
[Extreme][Dave]:    And how are the kids?
[Hard][Michael]:    Great. Amanda, too. Wonderful. She sends her love. So how's the job?
[Hard][Dave]:    Good, thanks, yeah. New supervisor, Steve Haines. He's on that TV show.
[Extreme][Michael]:    Really? Good guy?
[Extreme][Dave]:    He's okay. Well, it was nice to catch up.

-If the player switches to Franklin, he's in a phone conversation with Lamar
[Hard][Lamar]:    Say again! How the fuck we get fired?
[Hard][Franklin]:    Man, it was partly all that bullshit you pulled, and partly the repo's old man making me crash the car into the dealership.
[Hard][Lamar]:    You're the crazy-ass motherfucker in this partnership. You better spend 'em while you got 'em.

Later Franklin gets a phone call from Simeon
[Extreme][Franklin]:    Eh, look, man...
[Normal][Simeon]:    Look?! You were like a son to me. Employee of the Month! Does that mean nothing to you?
[Normal][Franklin]:    Man, the dude had a gun to my head.
[Easy][Simeon]:    No loyalty! No integrity! You should have taken the bullet! My business, my totally legitimate business! You are fucked, my boy! Fucked!
)"},
    {"Daddy_s_Little_Girl", R"(
Michael is trying to watch TV
[Normal][Jimmy]:    Dude, do you even have a penis? Or are you one of those hermaphro-dudes born without genitals?
[Normal][Jimmy]:    You suck cock for fun, only secretly, and then you feel bad about it.

Michael runs up to Jimmy's room
[Normal][Michael]:    Goddamnit! Jimmy! Goddamnit!
[Normal][Michael]:    Really? 'Cause I keep hearing, "hermaphrodite" this, "suck cock" that.
[Normal][Jimmy]:    Go watch your linear entertainment. Go watch porn. Just go away.
[Normal][Michael]:    Fuck, you lazy shit.

Michael smashes Jimmy's TV
[Normal][Michael]:    Disrespectful little asshole!
[Easy][Jimmy]:    I can't believe you did that! That's my TV!
[Normal][Michael]:    You don't talk to me like that!
[Normal][Jimmy]:    I cant believe you... Mom was right about you. You don't know any better and you can't help it. But you're an asshole.
[Normal][Michael]:    Yeah? Well, why don't you do something, then? Besides just stand there. Why don't you hit me?
[Normal][Jimmy]:    Is that what you want? To be hit by your son?
[Normal][Michael]:    Yeah... No... I just want you to do something besides sit there... eating.
[Easy][Jimmy]:    Yeah, great. Thanks for the fucking guidance, dad. It means a lot.
[Hard][Michael]:    Wait! I'm just trying to help ya.
[Easy][Jimmy]:    Well nothing says 'I love you' like smashing my fucking TV. Nothing at all!

Michael apologizes to Jimmy
[Normal][Michael]:    I'm sorry. I just wish we could do things together.
[Extreme][Jimmy]:    Yeah, what things?
[Normal][Michael]:    I don't know. Go for walks. Play ball.
[Hard][Jimmy]:    You know I have bad glands.
[Normal][Michael]:    Bike ride then.
[Easy][Jimmy]:    Bike ride? You want to go on a fucking bike ride? Fine! Fine, let's go on a fucking bike ride!

Michael and Jimmy head outside
-If Jimmy changes the radio station
[Normal][Jimmy]:    Sure you have. No wonder I'm so fat, you feed me all this bullshit! 
[Normal][Jimmy]:    I'm going gray listening to this crap. Station change. Fuck yeah, my jam!
[Hard][Jimmy]:    If I'm hanging with you, I'm listening to my music. Oh hella yeah.
[Extreme][Michael]:    Driver's choice.
[Extreme][Michael]:    Tyrant.
[Extreme][Michael]:    Old man despot.

Michael and Jimmy drive to Vespucci Beach
[Hard][Jimmy]:    This day was going so well until you showed up, you know that? Urgh...
[Normal][Michael]:    Yeah, well, you're lucky to even be allowed out of the house after that boat stunt.
  One line split into 2:
[Hard][Jimmy]:    What's the big deal? If anything goes wrong you can just fake your death, and start all over. 
[Hard][Jimmy]:    How am I meant to develop my own moral sensibilities when yours are so unbelievably fuck-faced?
[Normal][Jimmy]:    Seriously, some guys borrow your boat-
[Normal][Michael]:    Borrow?! You were hiding in the head crying kidnap!
[Hard][Jimmy]:    They just took receipt of your property with payment pending.
[Hard][Michael]:    If it was anything other than what you told me, then that's on you!
  One line split into 2:
[Hard][Jimmy]:    Alright! They fucking stole it! And who knows what they would have done if they found me! 
[Extreme][Jimmy]:    But I didn't expect or want them to get killed!
[Normal][Michael]:    You think I'm going to let some guys ride off with my son?!
[Hard][Jimmy]:    Look, I knew you were a bad guy but...
[Extreme][Michael]:    Oh, a "bad guy?"
[Hard][Jimmy]:    A crook, a killer, a thief, a liar!
[Hard][Michael]:    I guess I been all those things one time or another, right? It's just...
[Hard][Michael]:    I always thought I was the good guy.
[Hard][Jimmy]:    God help the morally bankrupt planet your generation have left us, if you're the good guy.
[Hard][Jimmy]:    Anyway, I always knew you were the kind of person who didn't let other people get in the way. But I hadn't, like, seen that happen before.
  One line split into 2:
[Hard][Michael]:    Yeah, well, that's me, Jim. 
[Hard][Michael]:    And I been trying my best to get things under control for the last ten years, but that was an extreme fucking situation, and I had to act.
[Extreme][Jimmy]:    A normal person wouldn't have done that.
[Extreme][Michael]:    Yeah, well, I had to. To protect you.
[Hard][Jimmy]:    Yeah, keep telling yourself that, when you see their faces every time you close your eyes.
  One line split into 2:
[Easy][Jimmy]:    Why do I always have to hang out with you? What about Tracey, huh? Why don't you ruin her day for once? 
[Hard][Jimmy]:    So, um, where are the bikes?
[Hard][Michael]:    At the rental place.
[Hard][Jimmy]:    You? Rent?
[Normal][Jimmy]:    I just thought you'd cruise around till you found an old lady on her way to the shops, knock her to the road, and cycle off on her bike.
[Hard][Michael]:    What do you take me for?
[Hard][Jimmy]:    Are we seriously having this conversation?
[Normal][Michael]:    Hey, I don't just rob anyone.
  One line split into 2:
[Hard][Jimmy]:    Yes, you do... I don't even think you know who you rob. They're anonymous to you. 
[Hard][JImmy]:    They've got something you want, and fuck them for standing in the way.
[Hard][Michael]:    No one complains when the guys at the hedge funds take what they can. What I do, it...
[Normal][Jimmy]:    Actually, dad, they do complain. There are some serious complaints. Protests even.
[Hard][Michael]:    Mister fucking morality.
[Hard][Jimmy]:    Here's a couple of morals to live by, don't kill people, and bankers are fucking scumbags.
  One line split into 3:
[Hard][Michael]:    Oh, you're anti-bankers now? Now that's a bandwagon if I ever saw one.
[Hard][Michael]:    Hey, I got an idea. Let's get mom to paint you a protest sign and we'll send you out into the street, huh?
[Normal][Michael]:    Hell, God knows you got time for it, with no TV and no fucking job!
[Extreme][Jimmy]:    Maybe I'll take you up on the offer.
[Normal][Michael]:    I don't see you standing in front of a tank, son. Unless it's a digital one, and there's a homo in the cockpit.
[Normal][Jimmy]:    What's so funny about me wanting my voice to be heard? It's my generation who've been screwed over. The debt, the job market.
[Normal][Michael]:    Well, you ain't employed, but you ain't exactly struggling either. You know, at your age I was...
[Normal][Jimmy]:    I know! In prison! Well, I'm in prison too! And the fucking warden wants to take me on a fucking bike ride!
[Normal][Michael]:    You don't know hardship, you little shit.
[Hard][Jimmy]:    Well, you don't know what an asshole you are.
[Hard][Michael]:    Hey. I got news for you, a lazy shit like you would get eaten alive in the pen. They'd be licking their lips.
[Normal][Jimmy]:    Well, it's a good thing I'm not the most likely one in the household to be convicted of a felony then.
[Hard][Michael]:    Well, maybe they should bring back debtors prisons.
[Hard][Jimmy]:    I think they've got plenty to worry about, with wanted bank robbers going on stealing and murdering sprees!
[Normal][Michael]:    Oh, no worries there, Jim. Me and the government learned to co-exist, thank you very much.

-If Michael drives recklessly
[Normal][Jimmy]:    You're driving like a psychopath, Michael. Do you realize that? Or are you so high on your own outmoded sense of masculinity that you think this is normal?
[Normal][Michael]:    Shut your pie hole. I think we'll both be happier if we can spend as little time in this vehicle as possible.
  One line split into 2:
[Hard][Jimmy]:    God, you think I've got learning difficulties, huh? 
[Hard][Jimmy]:    Take a good long look in the mirror, pal. I'm not the one who doesn't respect my fellow human being.
[Hard][Michael]:    No. Not unless they're a 'Spic', or a 'Jew-boy', or an 'ass-munching homo'.
[Hard][Jimmy]:    Oh, there was me thinking there's a difference between witty banter arising from a sense of competition…
[Extreme][Jimmy]:    And mowing someone down in the street!
[Easy][Michael]:    Hey, I never said you had learning difficulties, Jim.
[Hard][Jimmy]:    Well, I do, and you never cared.
[Easy][Michael]:    I just said that Dr. Friedlander thought that maybe you had problems relating to people.
[Normal][Jimmy]:    Relate to my asshole, old man.

-If Michael gets a wanted level
[Easy][Jimmy]:    The cops! Dad, I'm not a juvenile anymore, I'll go to grown-up prison!
[Easy][Jimmy]:    You know what prison will be like for me, Pop? My perfect white skin - I got bitch written all over me.
[Hard][Jimmy]:    If I go away, will you screw up my face so I'm not so pretty? Actually, not in the face.
[Hard][Jimmy]:    Can we, like, pay them off - or give them hand jobs?

After Michael loses them
[Normal][Jimmy]:    I'd prefer not to think about what just happened - just take us to Vespucci.
[Normal][Jimmy]:    The less that's said about that the better. Let's just go to the beach.

Michael and Jimmy arrive at the bike rental shop
[Easy][Jimmy]:    Here we are. The bike rental place. Please don't shoot the bike rental guy out of, like, force of habit.
[Hard][Michael]:    Hey, you. Two bikes.

Jimmy gets on a bike and both begin a race to Pleasure Pier
[Easy][Jimmy]:    If I beat you to the end of the pier, you're buying me a new TV.
[Easy][Jimmy]:    If I make it to the end of the pier first, you're going to buy me a big-ass new flatscreen.
[Normal][Michael]:    End the pier. Fine. But if you lose, you're going to do something with your life!
[Normal][Michael]:    End of the pier? Alright. But if I beat you, you're going to behave like a human being!

-If Jimmy wins the race
[Normal][Jimmy]:    Agh, woo! That's it. Number one, pal. You owe me a TV.
[Extreme][Michael]:    Hey, I never agreed to that.
[Easy][Jimmy]:    You know this is real nice, Dad. Bonding, good times.
[Normal][Michael]:    Yeah, well, I've given it my best shot. Hey, we're having fun, right?

-If Michael wins the race
[Easy][Michael]:    Looks like you're buying your own TV.
[Easy][Jimmy]:    You know this is real nice, Dad. Bonding, good times.
[Normal][Michael]:    Yeah, yeah, I've given it my best shot. Come on, we're having fun, right?

The dialogue remains the same regardless of the two alternative cutscenes
[Normal][Jimmy]:    You wouldn't know fun if it sat on your face.
[Easy][Jimmy]:    I mean, why do I have to hold your hand through this whole midlife crisis bullshit? And why don't you stick your nose up Tracey's butt sometimes?
[Easy][Michael]:    Because Tracey doesn't buy cars she can't afford so that thugs break in our house. Tracey doesn't get kidnapped or destroy my yacht.
[Normal][Jimmy]:    Well, that's just because she's too busy getting fucked by dudes to get on TV.
[Easy][Michael]:    You don't talk about your sister that way!
[Easy][Jimmy]:    Well, I'm sorry, but it's true. I mean, according to her Lifeinvader page, she's hanging out with producers and porno guys this afternoon.

Jimmy points to the boat where Tracey is at
[Normal][Jimmy]:    Actually, it's all happening right out there.
  One line split into 2:
[Normal][Jimmy]:    That boat that makes yours look like a refugee raft. 
[Normal][Jimmy]:    You know the kind of boat? The one that makes a young, impressionable girl, drop her pants and spread her legs.
[Normal][Michael]:    This is the reason you brought me here, isn't it? You fuck! Argh!
[Hard][Jimmy]:    Dad. No. Stop.

The scene on the boat
[Hard][Tracey]:    I'm a dancer. Yeah
[Normal][Michael]:    Come on, sweetheart. I'm taking you out of here.
[Easy][Tracey]:    Dad, you're embarrassing me, these are my friends.
[Extreme][Blake]:    Yeah, you're embarrassing her, dude.
[Normal][Michael]:    They're shooting porno here.
[Easy][Tracey]:    They shoot porno all over town. Mom rented our house to them last summer.
[Extreme][Blake]:    If those walls could talk.
[Extreme][Blake]:    Fuck, man! What's your problem? Asshole.
[Hard][Tracey]:    I like him! You're such a jerk!
[Normal][Tracey]:    Dad, you dumbass. These guys are serious.
[Extreme][Michael]:    Yeah, well so am I.
[Extreme][Freddy]:    Who's causing a scene on my fucking boat?! Ah, motherfuckers!
[Extreme][Freddy]:    I'm about to skin you alive!

Freddy and Blake get on the Seasharks and begin the chase
-If Michael stays in the water
[Extreme][Tracey]:    No, this is not an appropriate time to take a swim!
[Extreme][Tracey]:    What the fuck are you doing in the water?! Get back up here!
[Hard][Tracey]:    Stop fucking around in the water and get on the Seashark.

[Normal][Tracey]:    Shit. They're coming after us. Go into that outlet.
)"},
    {"Father_Son", R"(
Tracey and Amanda are arguing in the kitchen
[Easy][Tracey]:    You're such a fucking dictator!
[Hard][Tracey]:    Why the fuck not?
[Normal][Amanda]:    He's not staying the night! He's a bum! I don't even know why you are with him!
[Extreme][Tracey]:    Oh my God! I don't give a shit!
[Hard][Amanda]:    He's a bum! He is homeless!
[Hard][Tracey]:    Are you kidding me?! He doesn't have anywhere to go!
[Hard][Amanda]:    I do, you hear me? I don't care!
[Extreme][Tracey]:    Oh my God! You have no say...
[Hard][Amanda]:    Keep your mouth shut! What I do is none of your business!
[Easy][Amanda]:    And you watch your language! I'm gonna call your father and you're gonna get your ass kicked!
[Hard][Tracey]:    It's not fair! I hope someone cuts your brake cables!
[Hard][Amanda]:    I swear to God, you kill me!
[Extreme][Tracey]:    You kill me!
[Hard][Amanda]:    You know, it's not that I wish I...
[Extreme][Tracey]:    Stupid bitch...

Franklin arrives at the pool
[Extreme][Michael]:    What do you want?
[Easy][Franklin]:    Man, I come by for that drink you offered. That's all.
[Normal][Michael]:    I wasn't really serious about that.
[Hard][Michael]:    You're here, whatever. Sit.
[Easy][Michael]:    You're not gonna rob me again?
[Easy][Franklin]:    Man, I never robbed you. That was just a repossession.
[Easy][Michael]:    Okay... you call it whatever you wanna call it. I really don't care. What can I do for ya?
[Easy][Franklin]:    Shit, I just came by to see if there's somethin' I can help you with. I see you doin' well for yourself.
[Normal][Michael]:    Look... I'm retired.
[Easy][Franklin]:    Ain't you a bit young for the pipe, slippers, and starin' at a fuckin' sunset?
  One line split into 4:
[Easy][Michael]:    You know, I've been in this game for a lot of years, and I got out alive. That makes me the right age. 
[Easy][Michael]:    You look like a good kid. If you want my advice, you give this shit up. 
[Easy][Michael]:    You work hard, screw over everybody that you love, hurt, rob, kill indiscriminately and maybe...just maybe, if you're lucky...you become a three-bit gangster. 
[Easy][Michael]:    It's bullshit. Go to college. Then you can rip people off and get paid for it. It's called capitalism.
[Normal][Franklin]:    Hmm, so what I saw the other day was like... when a corpse briefly reanimates itself and terrorizes everyone, right?
[Normal][Michael]:    What you saw the other day was a guy dealing with pests.
[Normal][Franklin]:    I guess I never saw myself as just a fuckin' pest.
[Normal][Michael]:    Well, then today's lesson's all about humility. Tomorrow we'll try a training montage.
[Hard][Franklin]:    A training what?
[Normal][Michael]:    Nothin'. I was just lost in an eighties movie fantasy.
[Hard][Franklin]:    Yeah, I can see you spend a lot of time there.
[Hard][Michael]:    Yeah, as much as I can.
[Normal][Franklin]:    So that's why you here in Vinewood, then, right?
[Normal][Michael]:    Maybe I'm here because I'm just an idiot who thinks that imported palm trees are a good substitute for not really knowing what the fuck you're doing on this earth.
[Normal][Franklin]:    Jesus, man. You a good time, you know that?

Michael gets up
  One line split into 2:
[Normal][Michael]:    I'll tell you what, least I can do is buy you that beer. 
[Normal][Michael]:    There's a little bar I like, it's not too far from here. Let's go.
[Hard][Franklin]:    Alright, man. I'm following you.
[Normal][Michael]:    We're taking my wife's car.
[Normal][Michael]:    Let's take Amanda's car.

Michael gets a call from Jimmy
[Normal][Michael]:    Hey Jim, I'm going for a drink w...
[Easy][Jimmy]:    Dad, shit! I'm in our boat going down the Western Highway! It's... it's been stolen!
[Easy][Michael]:    What? The yacht's been stolen?
[Easy][Jimmy]:    I was trying to sell it. I know you didn't want it sold, but I need money, and... they don't want to buy it, they just want to take it! I'm hiding in the head!
[Easy][Michael]:    You're insane! Alright, I'm coming...for my boat!
[Easy][Michael]:    Alrighty, then. Change of plans. My darling boy is in trouble.
[Hard][Franklin]:    I'll do what I can to help with that, man.

They start driving
[Normal][Michael]:    Lesson number one: don't ever have kids.
  One line split into 2:
[Normal][Franklin]:    Hey, man, look, if I had kids, I don't think no parenting issues would arise over who had boat privileges and who don't. 
[Hard][Franklin]:     Shit, motherfuckers be lucky to sit in a bathtub.
[Hard][Michael]:    Shit, things that desperate, huh?
[Extreme][Franklin]:    Nah, but, you know, shit, I was making a point.
[Hard][Michael]:    Mythologizing self-deprecation. I know it well
[Normal][Franklin]:    Yeah man, but shit, where the boat at?
[Easy][Michael]:    Little shit's been hijacked. They're somewhere on the Western Highway.
[Hard][Franklin]:    Man, ain't you worried?
[Normal][Michael]:    About my boat? Yeah, I am.
[Easy][Franklin]:    But you can always buy another boat.
[Normal][Michael]:    Yeah, tell my accountant that.
[Normal][Franklin]:    Man, you can always get credit for one.
[Easy][Michael]:    And have you come and repo it? No thank you.
[Normal][Michael]:    I ain't your homie. I'm someone you wanna impress.
[Easy][Franklin]:    Really? Man, I thought you was retired. Why the fuck do I want to impress some slipper-wearing motherfucker?
[Easy][Michael]:    Because I can still teach you a thing or two. Maybe help you open the door to all the joys that boat-related parenting issues entail.
[Normal][Franklin]:    So I'ma help you get this boat back, right?
[Extreme][Michael]:    That you are, my friend.

They reach the boat
[Easy][Michael]:    Oh! There! There! There it is! That's my boat!
[Easy][Franklin]:    Your boat's in a fuckin' hurry, man.
[Hard][Michael]:    Yeah, well, we'll catch 'em.
[Extreme][Franklin]:    We got a plan?
[Hard][Michael]:    Sure. Once I get us up close, you're the boarding party.
[Hard][Franklin]:    More like the falling-in-traffic party.
[Normal][Michael]:    You'll be fine. Anything happens, I got a piece in the glovebox. I'll cover you.
[Hard][Franklin]:    Oh yeah, man. Fine. Just fucking fine. So you thought of everything, right?
[Hard][Michael]:    Well, you said you wanted to learn the old way of doing things. This is the old way.

Franklin jumps onto the yacht
[Hard][Michael]:    Hey, aren't they stealing this to sell it? Come on! Ah, too close!
[Extreme][Franklin]:    Get yo' ass out of here.
[Normal][Michael]:    Not the engine! Shit! The fucking engine!
[Normal][Michael]:    Oh, they didn't! They fucking shot the engine! Fuck!
[Hard][Michael]:    Throw him overboard!
[Hard][Michael]:    Hey, stop throwing assholes at me!
[Extreme][Michael]:    Knock it off, you thieving pricks.
[Hard][Michael]:    You got four lanes to throw guys at.
[Hard][Michael]:    Be cool, Frank. Be cool.
[Extreme][Michael]:    You're pirates, you know that?
[Normal][Michael]:    Okay! Now, go find Jimmy!
[Easy][Jimmy]:    Dad? Wait! You're the guy from the dealership?
[Hard][Franklin]:    Yup. And it's a long story, bro.

Jimmy gets snagged by the yacht's boom
[Easy][Michael]:    Jimmy! Kid, watch out for the boom! Fuck, hold on.
[Hard][Jimmy]:    Arrghh! Dad! Help! Help! Help!
[Normal][Michael]:    The fuck is wrong with you, kid?
[Easy][Michael]:    Don't "Dad" me, you little shit. You better hope she's still seaworthy!

One of the thieves falls off
[Hard][Michael]:    Yeeeeesh! Nah...shit. Come on, kid. Come on, kid.
[Hard][Franklin]:    Hey! Get me off of this damn thing!

-If Michael fails to catch Franklin
[Hard][Jimmy]:    Dad, don't be all butt-hurt. At least you got me out of there.
[Normal][Michael]:    You listen to me, you little shit! That kid just jumped off the hood of a moving car to save your ass, and now he's gone! And so is my boat!

Michael catches Franklin as he lands on the car's bonnet
[Normal][Franklin]:    Remind me not to come to you for parenting advice.
[Normal][Michael]:    All a-fuckin'-board? Let's stop this ship from sailing.
[Normal][Michael]:    That everyone? Alright, time to get the boat back.
[Hard][Jimmy]:    This is getting really weird, pop.

The car's engine starts to die
[Easy][Jimmy]:    Ooooh, now that doesn't sound good.
[Easy][Franklin]:    Damn, that's the engine, man. We ain't chasing shit in this thing.
[Normal][Michael]:    Don't break down. Not yet.
[Hard][Michael]:    Come on, stay with me. Stay with me...
[Extreme][Michael]:    Hold it together.
[Hard][Michael]:    Don't you die on me yet.

The truck manages to escape
[Easy][Michael]:    My fucking boat!
[Easy][Jimmy]:    Hey, it's just a thing! At least you've still got a son...
[Normal][Franklin]:    Eh. There's a chop shop back there, dog. You drive us there, we can get the ride fixed.

They drive to Los Santos Customs
[Easy][Michael]:    My boat!
[Hard][Jimmy]:    It's just a thing.
[Easy][Michael]:    My boat.
  One line split into 2:
[Normal][Jimmy]:    Please stop doing that... Listen... I fucked up, okay? I'm not going to lie.
[Easy][Jimmy]:    That was a really bad judgment call, but... shit, Dad, I nearly died, and all you give a shit about is this fucking boat?!
  One line split into 2:
[Normal][Jimmy]:    All we do is scream at each other. No wonder I can't get a job...it's all your fucking fault.
[Normal][Jimmy]:    Or, it's not... but it's partly your fault. I... I mean, I just want to impress you.
[Easy][Michael]:    By selling my boat to some gangbangers?
[Normal][Jimmy]:    I know it sounds dumb when you put it like that, but all you do is daydream or get angry...
  One line split into 4:
[Normal][Michael]:    Look, I love you, Jimmy, but you're an asshole. 
[Easy][Michael]:    And right now, with my boat disappearing over the horizon, that's all I can see. 
[Easy][Michael]:    Franklin, would you do me a favor and give this kid a ride home after they've fixed this thing? 
[Hard][Michael]:    I want to headbutt the road in peace.
[Normal][Jimmy]:    Oh, great...leave me with the home invader!
[Hard][Franklin]:    I'll get it done, dog, no problem.
[Normal][Michael]:    Enough, alright? Enough. Franklin, do me a favor, call me a taxi, will you?
[Normal][Franklin]:    Hey, I need a cab as soon as you can send one. Los Santos Customs, by the airport. Aight, thanks.
[Normal][Franklin]:    Eh, man, we might be able to find the boat, you know.
[Hard][Michael]:    We ain't gonna find it, it's gone.
[Extreme][Franklin]:    Man, I can ask around...
[Normal][Michael]:    Don't worry about it, it's gone. I'll call the insurance company.
[Hard][Franklin]:    You covered for fire and theft, right?
[Hard][Michael]:    I'm guessing they don't get too many piracy claims on the Great Ocean Freeway, you know. Fuck, I hate paperwork.
[Hard][Franklin]:    Eh, so you, ehh, do much yachting?
[Extreme][Michael]:    Not anymore, no. I don't.
[Extreme][Franklin]:    Before, I mean, man.
[Hard][Michael]:    Nah, nah, not really. This little shit stays in his room all day, and I don't have many other people to go with, you know. I liked looking at it.
  One line split into 2:
[Hard][Michael]:    Yeah, you know, I'd come down to the marina, sit on the dock, pour myself a drink and look at her...Jacqueline.
[Exteme][Michael]:    It'd clear my head, you know, let me dream.
[Hard][Franklin]:    Jacqueline, huh? Well, maybe you need to do some other shit to fill your time. Dream other dreams, man.

They approach Los Santos Customs
[Normal][Franklin]:    Hey, this the place up here. I know this dude, man, his name Hao. He goin' look after.
[Easy][Michael]:    Take what's in my pocket...a couple of thousand bucks. That'll cover it, right?
[Extreme][Michael]:    So, you sure you're good?

Michael gets out of the car and jimmy moves to the front
[Hard][Jimmy]:    Ooo, and I'm gonna come up front.
[Hard][Michael]:    Get out and walk around.
[Hard][Jimmy]:    It's okay, I can just climb over.
  One line split into 2:
[Normal][Franklin]:    Look, I'm gonna get the ride fixed, man, and drop it back off at your house along with this dude. 
[Extreme][Franklni]:    It's all good though, man. You go and get your head right, alright?
[Normal][Michael]:    Alright. Listen, thanks for today. Appreciate it. You stop back out to the house, we'll talk.
[Normal][Franklin]:    Fo' sho', man. Hey, sorry we didn't get your boat, man.

Michael hails a taxi and gets into it
[Normal][Jimmy]:    Come on, man. Let's trick this whip, homie.

-If Franklin has not completed a street race
[Normal][Hao]:    Still need to get you out for one of the races, Franklin. See if you drive as fast as you talk.
-If Franklin has lost a street race
[Hard][Hao]:    Surprised you're not still licking your wounds after losing that race, Franklin.
-If Franklin has won a street race
[Hard][Hao]:    For a second, I thought you'd just come here to talk smack about that race you won.

Franklin gets Amanda's car fixed up
[Hard][Jimmy]:    Alright. Good as new.
[Extreme][Jimmy]:    Reconditioned, sweet.

Franklin leaves Los Santos Customs and drives Jimmy back home
[Hard][Franklin]:    I'ma take you home now.
[Normal][Jimmy]:    It's Franklin, right?
[Easy][Franklin]:    Yeah, Franklin. Or the credit fraud guy, the home invader, you know what, call me what you like, man.
[Normal][Franklin]:    Jimmy, ain't it? Or James?
[Normal][Jimmy]:    Jimmy. Or, just, like... Jizzle?
[Normal][Franklin]:    No man, I'll just stick with Jimmy, homie.
[Extreme][Jimmy]:    So, ahh, what's the deal, man?
  One line split into 2:
[Normal][Jimmy]:    You and my old man? I see you at the dealership. Then someone steals my whip. 
[Hard][Jimmy]:    And Pop is all like, he's been down there to talk to you guys.
[Hard][Franklin]:    Your pops did more than talk.
  One line split into 2:
[Hard][Franklin]:    Look, man, if he ain't tell you, I ain't gonna tell you. 
[Normal][Franklin]:    But I lost my fuckin' job and I thought maybe he could help me find a new one.
[Normal][Jimmy]:    Dude, my dad is retired. Like, fully. Like, his only marketable skills are watching TV and daytime drinking.
[Normal][Franklin]:    Man, look, I dunno, homie, he seems okay to me. Shit, he saved your ass.
[Extreme][Jimmy]:    You saved my ass.
[Normal][Franklin]:    Nah, nah, man. Well, well, maybe we good together, you know? Like, maybe we can get shit done we couldn't do separately.
[Hard][Jimmy]:    If it keeps him out of the house, that's cool by me.
  One line split into 2:
[Normal][Jimmy]:    Look, I'm sorry my dad lost you your job. It's hard out there. Tough. 
[Hard][Jimmy]:    I mean, I'm employmentally challenged at the moment.
[Normal][Franklin]:    Oh, you got fired, dude? Damn, that's rough.
[Normal][Jimmy]:    Not fired, as such, I didn't get a job.
[Hard][Franklin]:    I've been there, homie. You been putting them resumes out there, but no one's hiring, huh?
  One line split into 2:
[Normal][Jimmy]:    No, I, uhh, I didn't get a job. I've never had a job. It feels like hard work, life. 
[Hard][Jimmy]:    The days just kind of disappear. Hey, you play Righteous Slaughter?
[Extreme][Franklin]:    Nah. Not since the first couple.

Franklin and Jimmy arrive back at Michael's home
[Normal][Jimmy]:    Yo! So, like, since we're both unemployed, like, we could run together, you know?
[Extreme][Franklin]:    Yeah, I'll think about it, homie.
[Normal][Jimmy]:    Or, or, we could just, like, chop it, y'know? Play darts or get our drink on? Strip clubs? Come on, dude, I get real crazy.
[Easy][Franklin]:    Yeah, I got your number should I need it, man. But, uh...hey-hey, you know what? Man, go easy on your pops, dog. Alright?
[Hard][Jimmy]:    Alright. Church.
[Normal][Jimmy]:    My brother from another mother. I mean... I-I hope so 'cause my mom was kind of a skank back in the day. See ya!
)"},
    {"Franklin_And_Lamar", R"(
Michael's first discussion with Dr._Friedlander
[Easy][Dr._Friedlander]:    Your son, James. He's a good kid?
  One line split into 3:
[Easy][Michael]:    He's a good kid? A good kid? Why? Does he help the fuckin' poor? 
[Easy][Michael]:    No. He sits on his ass all day, smoking dope and jerkin' off while he plays that fucking game. 
[Easy][Michael]:    If that's our standard for goodness, then no wonder this country's screwed.
[Hard][Dr._Friedlander]:    And what about you?
[Hard][Michael]:    What about me?
  One line split into 2:
[Easy][Michael]:    I didn't have the advantages that kid has. 
[Easy][Michael]:    By the time I was his age, I'd already been in prison twice. I robbed banks, I ran whores, I smuggled dope.
[Easy][Dr._Friedlander]:    And you consider them achievements?
[Easy][Michael]:    These were the opportunities I had. At least I took 'em.
[Easy][Dr._Friedlander]:    And where did these opportunities get you, Michael?
  One line split into 3:
[Easy][Michael]:    They got me right...fuckin' here! 
[Easy][Michael]:    The end of the road! With a big house and a useless kid, and I'm stuck talking to you because no one else gives a shit. 
[Easy][Michael]:    Oh, I'm living the dream, baby, and that dream is fucked! It is... fucking fucked!
[Easy][Dr._Friedlander]:    Let it all out.
[Normal][Michael]:    I think I just did.
[Easy][Dr._Friedlander]:    Oh, well I, think that's all we have time for. Same time next week?
[Normal][Michael]:    I gotta tell you, I ain't too sure this shit is working for me.
[Easy][Dr._Friedlander]:    Well, a sense of overriding futility is a vital part of the process. Embrace it.
[Hard][Michael]:    Whatever you say, Doc.

Scene at the walkway besides the beach
[Hard][Michael]:    I know just how you feel.
[Hard][Lamar]:    Man, shit gotta be around here somewhere.
[Easy][Franklin]:    Unless they buried it under the sand, fool. Another brilliant Lamar Davis production.
[Easy][Lamar]:    Man, fuck you. Hey, excuse me, homie, can you tell me where Bertolt Beach House is?
[Normal]Michael:    No, homie, I cannot.
[Hard][Franklin]:    Man, would you come on? Fuck!
[Easy][Michael]:    Actually, yeah. It's that house right there, with the yellow stairs.
[Easy][Lamar]:    Yeah, good looking out, homie, appreciate it.
  One line split into 3:
[Easy][Franklin]:    Man, get your stupid ass on. Damn! 
[Easy][Franklin]:    Why don't you ask him if he knows the fucking owner? 
[Easy][Franklin]:    Or better yet, do some sky-writing that reads there's a couple of niggas here about to boost some cars in case somebody didn't realize.
[Easy][Lamar]:    See, what you don't realize is, we ain't boosting. This shit is legit business.
[Easy][Franklin]:    Legit? Oh yeah, I forgot, huh? 401Ks, tax returns and all. Yeah, right.
[Easy][Lamar]:    You the one all pumped up on doing this lick, nigga. I'm getting my money in the hood, I'm straight, fool. I'm cool.
[Easy][Franklin]:    You cool? Cool what? Slinging dope and throwing up gang signs? Yeah, right.
[Lamar]:    Whatever, homie.
[Easy][Lamar]:    Yeah, homie, this the spidnot right here. Your boy Simeon wasn't bullshitting.
[Hard][Franklin]:    Man, get your ass in there.
[Normal][Lamar]:    Bring your ass, fool. Always trying to boss somebody.
[Normal][Lamar]:    Damn. This nigga must got the baby dick.
[Normal][Franklin]:    Yeah, and all this shit paid for with bad credit.
[Normal][Lamar]:    Whoohoo. Come to Daddy. Which one you want, nigga?

-If Franklin doesn't decide
[Extreme][Lamar]:    It ain't this complicated.
[Extreme][Lamar]:    You goin' call this or what?
[Hard][Lamar]:    Come on. Which one of these motherfuckers you want?
[Extreme][Lamar]:    I'm about to take away your privileges.
[Extreme][Lamar]:    Makin' decisions - it's business 101.

-If Franklin enters the 9F Cabrio
[Normal][Lamar]:    You always was an old choosy motherfucker.
[Extreme][Franklin]:    Only child.
[Hard][Lamar]:    Aw, you ballin' hard with the drop top, huh?
[Extreme][Franklin]:    I might just be.
[Normal][Lamar]:    Whatever, nigga, it ain't gonna make you go no faster. Hit me on the speakerphone, I'm movin'!
[Normal][Franklin]:    Oh, it's like that, nigga?

-If Franklin enters the Rapid GT
[Normal][Lamar]:    Like that? Bobby big dick on the nigga, huh?
[Hard][Franklin]:    Shit, for real, homie!
[Easy][Franklin]:    Damn, this motherfucker got a robo-roof and everything, nigga!
[Normal][Lamar]:    He shoulda paid the nizote!
[Normal][Franklin]:    Man, you got to grind to keep that shit. Now it's back on us.
[Normal][Lamar]:    Hell yeah, I wanna see what it do. Hey, hit me on the speakerphone, lo.
[Hard][Franklin]:    Oh, it's like that? Fo' sho', homie.
[Easy][Lamar]:    Right up here, homie. I'm 'bout to go nice and slow for yo' bitch-ass.

-If Franklin gets in front of Lamar
  Option 1
[Hard][Lamar]:    How the fuck you get in front of me?
[Hard][Franklin]:    Your slow ass should be askin' why I didn't get here sooner.
  Option 2
[Hard][Lamar]:    How the fuck did you get up front?
[Hard][Franklin]:    I been faster than your lanky ass since kindergarten.
  Option 3
[Hard][Lamar]:    That you in front, you fat motherfucker?
[Hard][Franklin]:    Who else, you lanky bitch?

The drive
[Normal][Franklin]:    Eh, remember, we got to be careful with these rides, homie. 'Cause Simeon ain't about to dock my pay again...
[Normal][Lamar]:    Homie, man, if you need some bread, I could hook you up with JB's tow truck. It ain't got glamor but there's some money to be made.
[Normal][Franklin]:    So him and Tonya can smoke crack in peace? Homie, I'm good.
[Extreme][Lamar]:    Come on, Frank.
[Extreme][Franklin]:    If you wanna chuck them thangs?
[Normal][Lamar]:    Damn, dog, how much we gettin' for these repos? I'ma be one reluctant motherfucker givin' this up.
[Normal][Franklin]:    Man, there's enough bad credit going around, homie. It's like there's an endless supply in this fucked-up-ass country.
[Normal][Franklin]:    Hey, open up, homie. Gimme some room.
[Normal][Lamar]:    You want room? Go lose some weight with your fat ass.
[Hard][Lamar]:    This meant to be your shit.
[Hard][Franklin]:    I'll come at you from the shoulders, homie.
[Extreme][Franklin]:    Get out the road!
[Easy][Franklin]:    Hey, dog, we'd be doing Simeon a disservice if we didn't test these rides out.
[Normal][Lamar]:    He ain't even gonna know if they good if we don't push them to the brink. You feel me?
[Normal][Lamar]:    Up here, through the studio. Let's show these movie people how we do!
[Hard][Franklin]:    Oh, we filmin' shit here! Huh?
[Hard][Lamar]:    Eh, eh. Down this alley here.
[Normal][Lamar]:    Remember this is Yetarian's car.
[Extreme][Lamar]:    Left here.
[Extreme][Lamar]:    We hangin' a left.
[Normal][Lamar]:    Whoo! You wanna get whips like this, you gotta stay on yo' gridnind.
[Normal][Franklin]:    nigga, and do some time over nickels and dimes? I'll stick to repos, dog.
[Hard][Lamar]:    Keep up, homie!
[Extreme][Lamar]:    We goin' right.

They turn onto Vespucci Boulevard, narrowly missing a bus
  Option 1
[Normal][Lamar]:    Left here. We going through the parking lot.
  Option 2
[Normal][Lamar]:    Left, through the parking lot.

They enter the parking lot
[Extreme][Lamar]:    You ain't even testin' me.
[Extreme][Franklin]:    Screw you too, homie.
[Extreme][Lamar]:    Keep bustin', loc!

They race underneath the Arcadius Business Center, before emerging at the entrance to the Union Depository
  Option 1
[Normal][Lamar]:    We buzzing the Union Depository, motherfucker!
[Normal][Franklin]:    That super-bank? Motherfucker, you a idiot.
  Option 2
[Hard][Lamar]:    I'ma make a withdrawal, homie.
[Normal][Franklin]:    You dumb motherfucker. That's the Union Depository.

They arrive in the parking lot
-If Franklin Wins & the car is in good condition
[Easy][Franklin]:    What you go and slow up the road for, dog? Move over so the traffic can flow through.
[Easy][Lamar]:    Whatever, nigga. I'll let something flow through your ass.
[Normal][Franklin]:    Dog, I ain't too sure that joke works, dog.

-If Franklin wins & the car is damaged
[Normal][Lamar]:    That bucket don't look like the whip we picked up.
[Hard][Franklin]:    Existing damages, motherfucker.

-If Lamar wins
[Hard][Lamar]:    Finally, bitch! When you goin' learn how to move something?
[Hard][Franklin]:    I'll show you how to move something, nigga!

Sirens are heard in the distance
[Normal][Lamar]:    Oh shit, the one-time!
[Easy][Franklin]:    Be cool, fool, we got the paperwork.
[Easy][Lamar]:    Whatever, you explain that shit. I'll see you at the dealership!
[Normal][Franklin]:    Explain that shit my ass!

Scene at Premium Deluxe Motorsport
[Extreme][Jimmy]:    I don't get you, bro.
  One line split into 3:
[Easy][Simeon]:    You are a racist and I don't like you, and I will not sell you this car, I will not. 
[Easy][Simeon]:    You make my skin crawl, you neo-Nazi. Ah, you are all the same, you are disgusting.
[Normal][Simeon]:    This racist insulted me.
[Easy][Lamar]:    Ay, wassup, fool? Who you callin' a nigga?
[Easy][Jimmy]:    No, no. I'm not callin' nobody a nigga.
[Hard][Lamar]:    Man, what the fuck?
[Easy][Jimmy]:    I...I mean... N-word. I, I... That...that's not cool, man. I don't say that.
[Easy][Lamar]:    You fuckin' right, and you'd better keep it right, 'cause this man right here, he's an international businessman, a multi-culturalist.
[Easy][Simeon]:    That I could have not said better myself, ah? But seriously, maybe he's not a racist, but I don't think that he is man enough for a car like this!
[Hard][Jimmy]:    Wai...wait a second.
[Easy][Lamar]:    This guy right here? Him? Get him a hybrid. That's a real man's car.
[Easy][Simeon]:    I think you are right, Lamar. You'll get a tax rebate. I understand, money is an issue, eh.
[Easy][Jimmy]:    Money isn't an issue.
[Easy][Lamar]:    This is the best part, watch this when he reel him in, he gonna get all this fool's money, watch this.
[Easy][Franklin]:    Look, man, I gotta go. Hey, Simeon, I'm out! I'll holla at you, homie.
[Normal][Lamar]:    It's the best part, man.
[Easy][Simeon]:    So, Jimmy, are you sure you are man enough? Take the wheel, show me.
[Normal][Lamar]:    How 'bout we fall through, homie?

-If Franklin stays to watch Jimmy and Simeon
[Hard][Simeon]:    Excellent. Now listen to the quality of the stereo.
[Hard][Simeon]:    No, no. No, it's too much for you. You need a compact.
[Hard][Jimmy]:    Whoa. No way, man. Compact? I'm a high-roller, SUV guy. I just need time to think.
  One line split into 2:
[Hard][Simeon]:    This is the problem — only the weak use their brains, the strong use their balls. 
[Hard][Simeon]:    You're a time-waster — I should charge you for my time. How much I say per month? Double it.
[Hard][Jimmy]:    Whoa, whoa-... hey-... I want it, okay? I just don't have much collateral.
[Hard][Simeon]:    We take a cash deposit and your word you can meet the weekly payments.
[Hard][Jimmy]:    Weekly? I thought it was monthly payments.
[Hard][Simeon]:    Weekly, monthly, it doesn't matter. You are not a serious customer.
[Hard][Jimmy]:    Whoa, whoa, whoa, I'm serious, bro. Deadly. Church, bro. Just show me where to sign.
[Hard][Simeon]:    I am with a customer, Franklin.
[Hard][Simeon]:    Lamar is waiting for you.

Franklin and Lamar leave the dealership
[Normal][Lamar]:    This chump change. How am I gonna knock a bad, grown and sexy bitch if I ain't got a fat pee-zocket?
[Normal][Franklin]:    Who you trying to impress?
[Easy][Lamar]:    Your auntie, Denise. With all that ass, nigga, she got ass.
[Normal][Franklin]:    She grown, yeah. She grown into a fuckin' idiot.
[Normal][Lamar]:    Nah, she's sexy.
[Normal][Franklin]:    Sexy? She more like obsessed with sex, nigga.
[Normal][Lamar]:    Nah, mad for the penis. That's exactly how I like my women.

They arrive at Franklin's house
[Normal][Franklin]:    Man, shit, it's good to be home.
[Easy][Lamar]:    Wassup, can a loc come up in your crib?
[Easy][Franklin]:    Man, fuck you. I'll see you at work.
  One line split into 3:
[Easy][Lamar]:    Ah, nigga, don't hate me cause I'm beautiful, nigga. 
[Easy][Lamar]:    Maybe if you got rid of that old yee-yee-ass haircut you got, you'd get some bitches on your dick. 
[Easy][Lamar]:    Oh, better yet, maybe Tanisha'll call your dog-ass if she ever stop fucking with that brain surgeon or lawyer she fucking with. nigga...
[Extreme][Franklin]:    Hmph. Motherfucker.

Franklin enters his house
[Normal][Denise]:    Woo, honey. Y'all telling me. Oh, he here. We living on top of each other, and it ain't right.
[Normal][Denise]:    Shoo, shoo! Get on out of here. Okay, baby, I'll see you at that thing, you hear?
[Easy][Denise]:    I was on the phone, boy, don't be listening! Goddamn freeloader!
)"},
    {"Friend_Request", R"(
The scene at Lester's home
[Easy][Michael]:    Fuck you, Lester. You gotta let me in or what?
[Extreme][Lester]:    Gimme a minute.
[Hard][Lester]:    I was wondering when you'd show up.
[Normal][Michael]:    I was dead.
[Normal][Lester]:    Praise be! I guess you weren't very dead. You... need my help.
[Extreme][Michael]:    How do you know?
[Hard][Lester]:    'Cause you came here. Why else would you?
[Normal][Michael]:    I haven't been a good friend for you, Lester. I know that.
  One line split into 2:
[Hard][Lester]:    And you're gonna make it up to me by doing whatever I ask. 
[Normal][Lester]:    Or rather, I-I mean... I need something done, you need to know something, so, why not help each other?
[Normal][Michael]:    I gotta make some dough.
[Easy][Lester]:    So you're back in the game?
[Normal][Michael]:    I guess. Look, Lester, about what happened before...
  One line split into 3:
[Normal][Lester]:    I know you never mentioned my name. 
[Normal][Lester]:    I know I'm not on any lists anywhere, I know you never betrayed me. 
[Easy][Lester]:    As for you, you gotta figure that I never told anyone, that instead of gently decomposing in North Yankton, you're angrily decomposing in Los Santos with a shrink... and a wife who don't love you no more.
[Hard][Michael]:    Yeah... yeah, well. Since you put it like that...
[Normal][Lester]:    Hey, shut up a minute, I'm getting an EyeFind alert. That little college boy, sack of shit, phony fuck!
[Normal][Michael]:    Who? Jay_Norris?
[Normal][Lester]:    Yes. That fuck is a lying bastard, I've read his fucking emails, he's a fucking cheat.
[Normal][Michael]:    I-I-I heard him say that he saved America...
  One line split into 2:
[Normal][Lester]:    What, by outsourcing all the jobs?! By selling us little bits of plastic, restricted-access shit? 
[Hard][Lester]:    Well now it's payback time, you lying turd.
[Easy][Lester]:    You are about to get that white-collar gig that you've always dreamed of, Mikey.
  One line split into 2:
[Easy][Lester]:    Here, take this err, fashionably retro, "weird-for-a-45-year-old-man-but-I-cannot-let-go-of-the-1980s" bag, and dress yourself up like a billionaire math genius with low-level Asperger's. 
[Hard][Lester]:    You better be ready for the minor glitch of your repulsive pseudo-messianic life.
[Normal][Lester]:    Get out of here! Call me when you're ready. We're about to put the Darwinism back in social Darwinism, and brother, it's gonna be fun.
[Easy][Michael]:    You fuckin' kiddin' me? I'm a bank robber, not a web designer.
[Easy][Lester]:    So, we'll go robbing... soon. I'll find something. Just like the old days.

-If the player doesnt immediatly leave Lester's house
[Hard][Lester]:    I'd offer you something, but you were just leaving.
[Hard][Lester]:    Was there something else?
[Hard][Lester]:    As much as I love "catching up"...
[Normal][Lester]:    Please excuse me, I've got something shameful to do.

Michael enters the clothing store
[Easy][Michael]:    Ah, excuse me. I got this interview with this tech company. I'm thinking I need something, I don't know... geeky, youthful.
[Normal][Michael]:    I didn't lose my job.

Michael calls Lester
[Hard][Michael]:    I'm all dressed up. Now, you wanna run me through this thing?
[Easy][Lester]:    The prototype is somewhere in the Lifeinvader office. Find it, and fit it with the device in your bag.
[Extreme][Michael]:    They just gonna let me in?
[Hard][Lester]:    Why wouldn't they, if you look the part? Hang around till someone opens the door and act entitled.

Michael meets Rickie at the Lifeinvader entrance
  One line split into 2:
[Easy][Rickie]:    Oh, great. PM's pushing for more functionality, but we are maxed. 
[Easy][Rickie]:    I mean, if anything, we have to strip features, especially if we're planning on releasing a fully-priced update a year later. Oh, my... you know, it's all this...
[Hard][Michael]:    Yeah, well, you know, you gotta do what you gotta do. You know?
[Easy][Rickie]:    Err, I mean, we're talking beta in Q4, maybe Q3. Look, milestones are one thing, but when design is changing its mind seemingly overnight, there's not much you can do about it... you know what I'm saying?
[Normal][Michael]:    Look, my Union-allocated smoke break's about up, so...
[Extreme][Rickie]:    Wait a minute, do I know you?
[Hard][Rickie]:    I-I-IT temp, right?
[Hard][Rickie]:    You know, you gotta do something for me.
[Normal][Michael]:    Ah, you gotta put it in a ticket.
[Normal][Rickie]:    Err, no. I'd like to keep this one out of the database, if you know what I mean?

Both enter the building and walk to Rickie's desk
[Hard][Rickie]:    I'm turning consultant when we release - consulting consulters.
[Normal][Rickie]:    Here you go. If you guys let me use the OS I requested, this wouldn't be a problem.
[Easy][Michael]:    Ah, you've been at it on this PC. This is a filthy hard drive, bro. Uh, got any antivirus software?
[Easy][Rickie]:    I think so. Behind this junk, on the left. Clicked an NSFW link, bro, bit me on the ass.
[Normal][Michael]:    Yeah, not safe for work, huh? You know, my son's computer runs into the same kind of problems. I'll close the pop-ups, see what I can do.
  One line split into 2:
[Hard][Rickie]:    Your son codes? Start 'em early, bro. You write your best stuff in your tweens. After that, it's just a hack job. 
[Extreme][Rickie]:    Might I tempt you with some organic chow or a fair-trade java?
[Extreme][Michael]:    Give me a second, will you?
[Hard][Rickie]:    Rocking out might get you in the right head space.
[Extreme][Michael]:    Bear with me, alright?
[Hard][Rickie]:    My glitch fixing is gonna be way down today.
[Hard][Rickie]:    You want to take a break for some air guitar, gimme a wink, bro.
[Extreme][Michael]:    Almost cracked it.
[Hard][Rickie]:    You wannna massage? 'Cause my hands are free.
[Hard][Michael]:    See, I don't have the manual on me.
[Hard][Rickie]:    I need to write some product, broheim. I'm feeling the itch.
[Hard][Michael]:    My son probably wrote this, the little shit bag.
[Hard][Rickie]:    This place is fueled by java, bro.
[Hard][Michael]:    These hacker kids. Always coming up with a new way to screw the network in the ass.
[Hard][Rickie]:    Might be why I get all these migraines. Seriously, it - it might be why.
[Hard][Rickie]:    Wow. Your job is actually kinda stressful too, ain't it?
[Hard][Michael]:    They gotta send me on another one of those seminars.
[Extreme][Michael]:    Scanning...

Michael removed the malware and leaves
[Normal][Michael]:    And that should do it. Why don't you try and keep things strictly "safe for work" from now on?
[Easy][Rickie]:    Hey, have you seen the prototype in the demo room? When Norris unveils it at the keynote, minds are gonna blow!
[Extreme][Michael]:    Yes, they are.
[Normal][Rickie]:    Dude, when it blue screens again, you're my guy.
[Hard][Rickie]:    Making history, dude. Hey, and we couldn't do it without the little guys!

Michael calls Lester
[Normal][Lester]:    Hey, Michael, hold on, hold on... domed! I domed ya!
[Easy][Michael]:    Lester? The thing's in the prototype, I'm going home to watch the keynote.
[Hard][Lester]:    Teabag time, my friend!
[Easy][Michael]:    Lester, did you hear me? Are you playing that game?
[Normal][Lester]:    Yeah, yeah, sorry, phone is rigged. What's your problem, you don't like shooters?
[Normal][Michael]:    They're all the same. Besides, you know me, I'm a movie guy. Classic Vinewood.
[Hard][Lester]:    Classic Vinewood ended 30 years ago. Now, it's just superheroes, romantic comedies and remakes, none of which interest me.
  One line split into 2:
[Hard][Michael]:    Hey, I believe this country can still make interesting movies. 
[Extreme][Michael]:    There's no better way to define American life than a two-hour plot in which the hero looks good and defeats evil.
[Normal][Lester]:    Ah, whatever you say...enjoy yesterday. Anyway, just call the device after he's unveiled it, and then we'll talk.

Michael returns home
[Hard][Tracey]:    Oh my God, you guys are so lame!
[Easy][Tracey]:    No, I'm watching Fame or Shame!
[Normal][Michael]:    Tough fucking tits! Gimme that...
  One line split into 2:
[Hard][Jay_Norris]:    Hey. This company has come a long way since we started it in my parents' pool house in East Carraway. 
[Hard][Jay_Norris]:    Today, you're about to witness a new phase. Full on, weapons grade, red alert, world domination!
  One line split into 2:
[Hard][Jay_Norris]:    We have put a billion people's private data in the public domain, and we have milked every penny we could in the process. 
[Hard][Jay_Norris]:    We have one of the youngest work forces in the world! An average age of only 14.4 years, that's not just impressive, it's revolutionary!
[Hard][Jay_Norris]:    Today, right here, we're about to make the next step! Prepare to witness... the future.
  One line split into 6:
[Normal][Jay_Norris]:    The Lifeinvader mobile device. Yes, we have invented something no one else has ever thought of. 
[Hard][Jay_Norris]:    A small personal computerized device. Now you're able to stay docked 24/7. 
[Hard][Jay_Norris]:    On the bus. You can dock. On the subway. Stay docked. You can be docked in at home, and at the same time, you're docking with some kids at the public pool. 
[Hard][Jay_Norris]:    We went to the guys at Fruit Computers and we told them we wanted to make our hardware as compatible as possible. 
[Hard][Jay_Norris]:    But you know what? They're not interested in "sharing" their technology. So we went and made it compatible anyway. 
[Normal][Jay_Norris]:    Now you can dock your Lifeinvader to an iFruit or any other device, and it'll take all the data off it and reformat it into Lifeinvader-friendly information.

Michael calls Norris
[Hard][Jay_Norris]:    Huh, hold on a second. I think someone's trying to dock with me.
 
-If Michael fails to call Jay in time
[Hard][Jay_Norris]:    At around this point in my presentation there was meant to be a call from my product team to introduce the device, but we're experiencing some technical difficulties.
[Hard][Jay_Norris]:    I hate to keep you waiting any longer, but trust me, it's worth it. And don't worry, I will fire several people for this.
 
Michael calls Lester
[Normal][Michael]:    Lest, that was heavy! You watching the news?
[Hard][Lester]:    I don't have to, I'm watching the markets. I'll be trading pure alpha 'till close.
[Hard][Michael]:    Alright. Hey, about that other thing, you know, the score?
  One line split into 2:
[Normal][Lester]:    Oh, yeah, yeah, absolutely. Let's do it. Put on a suit, look somewhat professional and meet me at my warehouse off the LS Freeway. 
[Hard][Lester]:    Oh, and I'm about to email you a link for the exchange. You can put in some trades of your own.
[Hard][Michael]:    I'm trying to stay off the day trading, but maybe I'll take a look.
 
Rickie calls Michael some time later
[Easy][Rickie]:    It's Rickie from Lifeinvader. I know you're the bro who deactivated Jay, bro.
[Normal][Michael]:    I have no idea what you're talking about, pal.
  One line split into 2:
[Hard][Rickie]:    What you do's your business, bro. Anyway, Jay really got a big head once people started calling him a god... guess you proved he wasn't one. 
[Hard][Rickie]:    They reintegrated my team in Burundi after the design got signed off, and now, my shares ain't worth dick.
[Normal][Rickie]:    I need work, and I thought maybe you could provide. I mean, I'm smart enough to track you down, aren't I?
[Extreme][Michael]:    I guess you are. Hey, I'll be in touch if anything comes up.
)"},
    {"Marriage_Counseling", R"(
Michael enters his home
[Hard][Michael]:    Hey Aman? Tracey?
[Hard][Michael]:    Amanda! Amanda!
[Normal][Michael]:    You better not be! Not in my house!
[Normal][Amanda]:    Fuck you, Michael! Go Away!
[Easy][Michael]:    I'm paying that turd a hundred and fifty bucks an hour to fuck my wife?
[Normal][Michael]:    In my own bed?
[Extreme][Amanda]:    Michael, go away!
[Normal][Kyle]:    Whoa! I'm sorry bro. She said you had an arrangement.
[Hard][Michael]:    You and I are gonna have an arrangement.
[Hard][Michael]:    I'm gonna arrange your fuckin' funeral.
[Normal][Kyle]:    I'm really sorry, bro. I'll comp the session, I promise.
[Hard][Michael]:    You're a dead man!

Franklin walks up to the house
[Hard][Amanda]:    Hey, you...stop him!
[Hard][Michael]:    Get out of my way!
[Normal][Amanda]:    Michael, calm down!
[Hard][Franklin]:    What the fuck is going on?
[Normal][Amanda]:    Nothing happened, it was all a misunderstanding.
[Normal][Michael]:    She fucked a prick in my bed.
[Hard][Franklin]:    You bullshittin' me?
[Extreme][Amanda]:    It wasn't like that!
[Extreme][Michael]:    You in?
[Normal][Franklin]:    Fuck it, I'm in. Let's roll, let's get this motherfucker.
[Normal][Amanda]:    Just don't kill him!

-If player started as Michael
[Extremel][Franklin]:    This truck yours?
[Hard][Michael]:    Guy's doing some work for me. He'll get it back. Might have a dead body hooked to it, but he'll get it back.
[Extreme][Franklin]:    Oh? So we killing this dude?
[Hard][Michael]:    He'll wish he was dead. That a problem?
[Extreme][Franklin]:    Shit, a dog shouldn't shit in another dog's kennel.
[Extreme][Michael]:    Exactly. People have been shitting in my kennel for too long.

-If player started as Franklin
[Extreme][Franklin]:    You okay, homie? What happened?
[Normal][Michael]:    Guy bounced my wife is what happened.
[Extreme][Franklin]:    Which guy?
[Normal][Michael]:    Guy I'm paying to teach her tennis.
  One line split into 2:
[Normal][Franklin]:    The tennis coach? Aw that's fucked up man. 
[Extreme][Franklin]:    You rich dudes, homie. You know, back in the hood, man, we gotta watch out for the mailman, dog.
[Extreme][Michael]:    Yeah, I'm a cuckold, a snob, and a fucking cliché.

Michael and Franklin track the coach to his house
[Extreme][Franklin]:    Off to the left, right there.
[Normal][Franklin]:    Fuck man, I think we lost his ass.
[Easy][Michael]:    He lives somewhere up in the canyon, we'll find him.

Michael and Franklin arrive at the house
[Extreme][Michael]:    Okay, this is the turn.
[Hard][Franklin]:    Hey! He in one of these fucking houses?
[Hard][Michael]:    That's his car. Right there.
[Hard][Michael]:    The little prick's up there. Look.
[Normal][Franklin]:    Oh shit, coach doin' alright for hisself.
[Normal][Michael]:    Hey, asshole! You ran off before we could settle our debts.
[Normal][Kyle]:    Michael, bud! You got the wrong idea, man.

-If player started as Michael
[Extreme][Michael]:    If I got to go to a motel, she's got to go to a motel! Let her get crabs for a change!
[Extreme][Franklin]:    You got crabs?
[Extreme][Franklin]:    'Cause I like, uh, shook your hand and shit, man...
[Hard][Michael]:    No. Not anymore. Look, we got rules. Not in the house. Not guys I got to look in the eye. Or pay for the privilege!
[Hard][Franklin]:    Oh, this dude's your employee? Now that's a line you don't cross, man.
[Extreme][Michael]:    For any kind of man it is.
[Hard][Franklin]:    Oh fuck yeah, let's have some strong-ass words with this little byatch.
[Extreme][Michael]:    Oh, we're gonna communicate nice and clear, that's for shit sure.

-If player started as Franklin
[Hard][Franklin]:    How you catch 'em?
[Easy][Michael]:    It wasn't hard. They were in my house. In my own bed, on top of each other!
[Normal][Franklin]:    Man, this dude got some explaining to do.
[Easy][Michael]:    The whole thing was kinda self explanatory, Frank. And what we're about to do won't need much context either.
[Normal][Franklin]:    Shit. Let's coach the shit out this motherfucker.

The scene where they winch down the house
[Easy][Michael]:    There's a winch in the back of the truck. Tie the cable to one of those supports up there.
[Easy][Franklin]:    You finna pull his deck down?
[Easy][Michael]:    Hey, that prick pulled my marriage down.
[Normal][Franklin]:    Man, you really going to be this fucking dramatic?
[Easy][Kyle]:    I told you I'd comp the session, bud!
[Easy][Michael]:    Well there were a lot of freaking sessions, bud! I'm thinking you were working on more than just her backhand!
[Easy][Kyle]:    Mandy's backhand has come a long way, bro. But sometimes it's got to get worse to get better.
[Easy][Michael]:    Yeah, well, maybe I should come up there and practice my backhand... on your face!
[Easy][Kyle]:    Oh, bud. Your negative energy is seriously bringing me down.
[Normal][Michael]:    Oh, I hope it is, bud.
[Hard][Franklin]:    We hooked up, man.
[Easy][Michael]:    You come into my house, take my money and nail my wife, are you fucking kidding me!?
[Normal][Kyle]:    I'm gonna stick up my hand and say that was uncool, bud.
[Normal][Kyle]:    My bad. Seriously.
[Easy][Michael]:    How fucking magnanimous!
[Easy][Michael]:    May I please offer you my applause... You fucking motherfucker!
[Easy][Michael]:    Hey, we'll see how you'll like it when someone fucks with your shit!
[Normal][Kyle]:    Whoa, hey! Wait! You got the wrong idea, pal!
[Hard][Michael]:    Here we go! Let's see what happens.
[Hard][Franklin]:    Dude, you are properly crazy.
[Hard][Franklin]:    Aw shit. You see this shit, dog?
[Extreme][Franklin]:    Man, homie ain't grubbing outside tonight, dog.
[Normal][Michael]:    Fuckin' A. Let's see how he liked that.
[Hard][Michael]:    Fuck him! And fuck his deck!
[Normal][Franklin]:    Eh, homie! I think you pulled a little more than the deck down.
[Extreme][Michael]:    It's a foolish man who builds his house on sand, baby.
[Extreme][Franklin]:    Hey man, I don't think my boy Matthew was thinking trucks when he wrote that shit.

The phone call on the way back home
[Easy][Kyle]:    Mr. De Santa! What the hell!? That's not my house.
[Easy][Kyle]:    Oh bro, I couldn't afford a place like that. I'm a tennis coach, I hit balls for a living.
[Hard][Kyle]:    I was just hiding there.
[Normal][Michael]:    Oh I'm scared lady. Just fucking terrified.
[Easy][Michael]:    "Green Light! Green Light! Martin Madrazo!" Fuck you.
[Normal][Franklin]:    Whoa. Homie. Martin? Martin Madrazo?
[Extreme][Michael]:    That's what she said.
[Normal][Franklin]:    Damn, dude's a kingpin, homie. Man, you better hope...
[Normal][Michael]:    I ain't hoping anything. Chick was hysterical. Chill out. The coach should be doing the Russian broad. Chick needs to chill the fuck out.
[Hard][Franklin]:    But you did just pull her life apart, homie.
[Hard][Michael]:    Yeah, I guess I did. All the more reason for coach to show her a good time.
[Hard][Franklin]:    Man, yo' ass is crazy. You like a sailor on shore leave making up for lost time.
[Hard][Michael]:    Oh, I been at sea alright. Everything they tell you that you want, kid, you don't need it.
[Extreme][Michael]:    Fast cars, big houses, beautiful women.
[Hard][Franklin]:    Man, you talking from the perspective of privilege, homie. To a hungry dude like me, man, all that shit look good.
[Extreme][Michael]:    Hey, the hunger's the first thing you lose. When that goes - the hunger and the anxiety - you get sloppy and you ain't worth a shit.
[Hard][Franklin]:    Well, what I just saw up there was a dude that's eatin' good, but he useful. Man, you could teach me a few things, dog.
[Hard][Michael]:    Yeah, lesson number one, don't meet the mother of your children in a skin joint.
[Hard][Franklin]:    Man, I don't know dog, strip clubs...
[Hard][Michael]:    Lesson number two, don't expect her to fucking change. She'll be picking your pocket, and rubbing up on other men until the day you die.
[Hard][Franklin]:    The advice I'm after's more work related, homie.

The shootout with Madrazo's goons
[Hard][Franklin]:    Shit, we got some heavies on us, homie.
[Normal][Franklin]:    Hey man, there's some mean lookin' motherfucking eses right behind.
[Hard][Michael]:    Are you kidding me? Kid, can you do something?
[Hard][Michael]:    Whoa, that was quick. Alright, help me deal with this.
[Hard][Michael]:    We can handle this, can't we? Screw 'em!
[Extreme][Franklin]:    Yeah, my nigga! That's it.
[Normal][Michael]:    Okay. We go back to my house, think about this.
[Normal][Michael]:    Wow. Shit. You did good. I mean, your aim's all over the place, but you were a help.
[Normal][Michael]:    Hey, don't get defensive. Go to a shooting range. Work on your aim. You'll do fine.
[Normal][Michael]:    Fine as wine. I got a few knocks. You okay? I mean, you did good, kid.
[Hard][Franklin]:    Man, I'm cool, man. I mean you - mentally.
[Hard][Michael]:    Mentally? Oh, man, I'm fucking excellent. My heart ain't pumped like that in years. Wooo! Yes! Fuckin' A bubba!
[Normal][Franklin]:    Man, you sound kind of manic. You just been green lit by the Mexican underworld ambassador to Los Santos.
[Normal][Michael]:    Trust me. We handled it. Whoever the fuck Martin Madrazo is, I've known worse.
[Hard][Franklin]:    We just handled a few low ranking clowns.
[Hard][Michael]:    We sit on it, we see what happens. Kid, there's no use second guessing. Felt good, man. Woooo! Yeah! Doin' something for a change. Ha!
[Hard][Franklin]:    Man, you know what? You are wasted sitting by that fuckin' pool, man.
[Hard][Michael]:    You're right. I need to do something. Scotch and sunshine and sitting on my ass? Fuck that, I'm better than that.
  One line split into 2:
[Extreme][Franklin]:    Damn skippy homie. All that knowledge up there. It's witherin' and dyin', dog. 
[Extreme][Franklin]:    You don't pass that shit on, it's gone, homie. I bet you know some shit...
[Hard][Michael]:    You wouldn't believe the shit I know.
[Hard][Franklin]:    Yeah? You taken some score?
[Extreme][Michael]:    There was a time, that was all I did.
[Hard][Franklin]:    Shit, well, you know, I can tell you some shit too.
[Extreme][Franklin]:    About this city I was born and raised in.
[Extreme][Franklin]:    Yeah, do that, man. This could be cool.

The confrontation with Martin Madrazo
[Easy][Michael]:    Hey, thanks for the help out there today, kid. I had no idea it was gonna get that hot.
[Easy][Franklin]:    Shit. Pulling houses off the hillside sure has a weird way of fucking with people.
[Normal][Michael]:    Yeah, well I thought I was through with all that shit. I don't know what the hell is going on.
[Normal][Franklin]:    Oh shit! I think we're about to find out.
[Normal][Martin]:    Do you know who I am?
[Normal][Martin]:    Do you know who I am?! Do you?
[Extreme][Martin]:    Do you, you?
[Extreme][Franklin]:    I think so.
[Normal][Martin]:    I know who you are. I know where you live.
[Extreme][Martin]:    Who are you?
[Normal][Martin]:    License.
[Easy][Martin]:    Now, Franklin, maybe help Mr. De Santa here. Who am I?
[Easy][Franklin]:    I think Martin Madrazo.
[Easy][Martin]:    Good boy. Now maybe give him a little of the background.
  One line split into 2:
[Easy][Franklin]:    Man, Martin Madrazo... Mr. Madrazo is a legitimate businessman.
[Easy][Franklin]:    He was wrongfully accused of...running a Mexican American gang and a narcotic ring, but the charges were dropped because of the witnesses came up... missing.
[Normal][Martin]:    Smart kid.
[Hard][Martin]:    Now, Michael.
[Hard][Martin]:    I've got a question for you.
[Easy][Martin]:    Why, did you pull a architecturally, significant, modernist wonder home down the hillside in Vinewood Hills?!
[Easy][Michael]:    I thought the owner was banging my wife.
[Easy][Martin]:    Well that was a strange house for a tennis coach.
[Normal][Michael]:    I wasn't thinking straight.
[Extreme][Martin]:    Clearly.
[Normal][Martin]:    Well, Natalia will need a hotel, while you finance the rebuild, won't she?
[Easy][Martin]:    Good. And I'm guessing here that, the rebuild will be somewhere in the... two point five million range?
[Extreme][Michael]:    Never better.
[Easy][Michael]:    Looks like I'm gonna have to postpone my retirement.
  One line split into 2:
[Easy][Michael]:    Fuck! Ah, man. I'm mortgaged up to my eyeballs. Look, I only know one way to make money. 
[Easy][Michael]:    I'm gonna have to give an old friend a call. Lester. I think he's in town somewhere. Might have to track him down.
[Hard][Michael]:    Just give me a little alone time, alright?

The phone call with Lester
[Easy][Michael]:    Hello. Is this still the number for Lester Crest?
[Normal][Lester]:    Who's asking?
[Normal][Michael]:    Who's asking "who's asking"?
[Easy][Lester]:    You're awful cagey... even for a dead man, Michael.
[Normal][Michael]:    Oh. You don't sound good, buddy.
[Normal][Lester]:    Tactful and charming even in death. Come see me, old friend.
[Normal][Lester]:    I'm living in Los Santos, just like you. Murrieta Heights...
[Hard][Michael]:    Whoa, whoa... hey, how do you... hello?
[Extreme][Michael]:    You fucker.
)"},
    {"Prologue", R"(
Introduction - Breaking into Depot
[Hard][Brad]:    Get down there!
[Easy][Michael]:    Alright, everybody pays attention, no one gets hurt.
[Easy][Trevor]:    Aarrgh! Open the door, or they'll get worse than hurt! Hey, hey, ah! Come on!
[Hard][Trevor]:    Argh, finally, you prick!
[Hard][Trevor]:    Let's go, shut up! Shut the fuck up!
[Hard][Trevor]:    Come on. In the back. Come on. Come on.
[Hard][Trevor]:    In the back. Come on. Let's go. Come on.
[Normal][Trevor]:    Get in here and deal with the guard!

-If Michael kills the hostage
[Hard][Brad]:    Hey! Prick! Behave yourself!
[Extreme][Brad]:    Hey! They're collateral!
[Extreme][Brad]:    If anyone's killing hostages, it's me.
[Extreme][Brad]:    No more of that, asshole. Come on.
[Extreme][Brad]:    So, you're not getting none from that ex-stripper.
[Extreme][Brad]:    This wasn't meant to get messy!
[Hard][Brad]:    We need'em alive, dick.

-If Michael is not getting into the room
[Extreme][Trevor]:    Where the fuck is your head, man?

Taking Hostages
[Easy][Michael]:    Hands behind your back.
[Extreme][Michael]:    Don't even think about it.
[Extreme][Brad]:    Get in there!
[Easy][Trevor]:    Sit tight. I'll handle the plastic.
[Easy][Michael]:    Don't blow yourself up!

-If Michael is standing still
[Extreme][Brad]:    M! Get these assholes in the closet!
[Extreme][Brad]:    I said the closet! Get 'em in there! Come on!
[Extreme][Trevor]:    What is the problem? Why are they still out here? You were meant to lock 'em down.

-If Michael kills a hostage
[Extreme][Brad]:    We need'em alive, dick!

Moving Hostages
[Hard][Brad]:    In the back! Come on!
[Easy][Trevor]:    All set. Phone it in.

Making the call
[Normal][Michael]:    I'm calling it.
[Normal][Michael]:    I'm making the call.

-If Michael doesn't call immediately
[Hard][Brad]:    Blow the door!
[Hard][Trevor]:    Blow the fucking door!
[Hard][Trevor]:    Call already.
[Hard][Trevor]:    Come on. Call it in!
[Extreme][Trevor]:    Detonate!
[Hard][Trevor]:    Get your cell out and dial.

Detonating Vault Door
[Easy][Trevor]:    Show me the money!
[Easy][Michael]:    Slow and steady, T. Slow and steady.

-If Michael stands still

-If Michael is not entering the vault
[Extreme][Trevor]:    Come on, man. The vault.
[Extreme][Trevor]:    The money's in here.
[Extreme][Trevor]:    The vault. Come on!
[Extreme][Trevor]:    The vault's back here!

Stealing Money
[Hard][Trevor]:    Oh, there it is.
[Extreme]Trevor:    That's the score.
[Extreme]Trevor:    We're just taking the non-sequential notes.
[Easy][Trevor]:    Oh... there's enough here for us all to enjoy!
[Normal][Michael]:    Depends on how you look at it.
[Hard][Trevor]:    We're done here, let's go.

-If Michael is not leaving vault
[Hard][Trevor]:    What's the hold up?

Jaspers' Last Stand
[Normal][Trevor]:    Coming out, B.
[Easy][Jaspers]:    Give it up! I got him! I saw your face. I'll remember you.
[Easy][Michael]:    You forget a thousand things every day. How 'bout you make sure this is one of 'em?
[Easy][Jaspers]:    I see it in his eyes. He's crazy.

-If Trevor is waiting
[Hard][Michael]:    No one's crazy. Alright, think. Be cool.
[Hard][Trevor]:    That's right, pal. I'm fucking crazy.
[Hard][Michael]:    Alright, look, you wanna live? Tell me you wanna live. Work this out.
[Hard][Jaspers]:    For sure I want to live! Tell him to put the gun down.
[Hard][Trevor]:    Ain't gonna happen, pal. Make a move. I got all day.
[Hard][Trevor]:    It looks like the cavalry ain't gonna show, pal!
[Hard][Trevor]:    I'll try to make this painless.

Crew Moving towards Garage
[Easy][Michael]:    Fuck! You didn't have to do that!
[Easy][Trevor]:    Let's get going. There'll be time for grieving later.
[Normal][Michael]:    Yeah, you got that right.

-If Trevor does not take cover
[Hard][Brad]:    Get your fucking head down, the doors are about to blow!
[Extreme][Brad]:    I'm ready to do this. Now, get in cover!
[Extreme][Brad]:    What are you doing? Find some cover!
[Hard][Michael]:    Get in cover, T.
[Extreme][Michael]:    Quit fucking around and get down!
[Hard][Michael]:    Wait until T's in cover, then set the charge.

Blowing up the Garage Door
[Easy][Brad]:    I'm setting the charges. They're on a timer, so brace yourselves!
[Normal][Brad]:    Just fucking perfect!
[Normal][Michael]:    Oh, fuck. You hear that? Sirens.
[Easy][Brad]:    Fuck the cops. T, hit the shutter switch.
[Easy][Trevor]:    What's this? Local resistance?

Engaging with Police
[Easy][Michael]:    It ain't supposed to go down like this.
[Easy][Trevor]:    It never is. Come on. Go.

Crew Walking towards Getaway Car
[Hard][Michael]:    Let's get out of here!
[Hard][Michael]:    We got a window. Let's go!
[Easy][Trevor]:    Can't be many more cops in this town.
[Easy][Michael]:    This is fucked, man. The thing is blown.
[Easy][Trevor]:    I got my share. It's still wide open!
[Normal][Brad]:    Car's up here! Let's go!
[Easy][Michael]:    Kid mighta bailed. This wasn't in the job description.
[Hard][Trevor]:    He better be there!

-If the Crew moves quickly
[Hard][Local Yokel]:    What took ya so long?
[Hard][Trevor]:    Shut the fuck up and drive.

Escaping with Getaway Car
[Easy][Brad]:    Did you see that shit? I fuckin' put that bitch's face against the glass. Did you see that?
[Easy][Michael]:    Yeah, you're a real stallion.
[Easy][Trevor]:    Bahbahbahbahbahbahbahbahbah!
[Normal][Local Yokel]:    Aww, fuck! How'd that happen?
[Hard][Local Yokel]:    Jeez, I think they're gonna...
[Easy][Michael]:    Aw, fuck! Local yokel's bought it!
[Normal][Brad]:    That guy's a dick...
[Hard][Michael]:    Fuck you too.
[Easy][Trevor]:    Come on! Let's get to the chopper! We move quick, we can beat the train.
[Hard][Michael]:    We're getting there!
[Easy][Brad]:    Man, I'll believe in this bird when I get eyes on it.

-If Michael drives slowly
[Hard][Michael]:    I say there's a chopper, there's a chopper. We stick to the plan, we're home free.
[Extreme][Brad]:    Alright! Yeah! Fuck 'em, man! Fuck 'em!
[Hard][Brad]:    Man, I thought this score was supposed to be an easy take? It's all gone crazy.
[Hard][Michael]:    Yeah. I hear you. We gotta follow the plan - everything'll work out.
[Hard][Brad]:    Pair of neurotic idiots.

Crash into the Train and Aftermath
[Normal][Brad]:    Cops. Coming our way.
[Easy][Trevor]:    Be cool... They ain't made this car yet.
[Easy][Brad]:    Shit! Shit! Shit! Road block!
[Easy][Trevor]:    Go right! Beat the train, man!
[Normal][Trevor]:    Arrgghh! Arrgghh! Jesus!
[Hard][Michael]:    You guys alright?
[Easy][Trevor]:    Fuck! Come on! Ditch the car, alright? We can go this way to the chopper.
[Easy][Michael]:    No, hey! Stick to the plan.
[Easy][Michael]:    Stick to the fucking plan! Come on.
[Easy][Brad]:    Where the fuck's the chopper? Fuck me, fuck, fuck!
[Hard][Brad]:    I'm gonna check around back.
[Easy][Trevor]:    Run! It's the fucking Feds! Someone must have fucking talked!
[Easy][Michael]:    Alright. Brad's gonna be fine, but we gotta get the fuck out of here.
[Easy][Michael]:    Aw, fuck! I'm hit! Ah, Jesus. T, you gotta get out of here.
[Easy][Trevor]:    Ain't gonna leave you Mikey!
[Easy][Michael]:    Go! God, I'm not gonna make it. Fucking gonna bleed out. Aw, go, go...

Trevor's gunfight
[Hard][Trevor]:    Die, you cocksuckers!
[Hard][Trevor]:    Fucking die, all of you!
[Hard][Trevor]:    Fuck you! Fuck you! Fuck you! Fuck you!
[Hard][Trevor]:    I'm standing here! Finish me!
[Hard][Trevor]:    Kill me, you pricks!

Trevor's escape and Michael's funeral
[Normal][Trevor]:    Where's the chopper?
[Normal][Trevor]:    Fucking stay back! You come near me, she's fuckin' dead! Stay back!
  One line split into 2:
[Easy][Priest]:    Michael was not always a good husband. Not always a good citizen. He did not die a hero's death. But he was a man. 
[Normal][Priest]:    Our Lord was crucified with two thieves, so perhaps... we should not judge.
  One line split into 2:
[Easy][Priest]:    We are born of sin, and we die in sin... and in this, Michael... was like anybody else. 
[Normal][Priest]:    Father... we do not know your infinite mysteries. But we know... that you will show mercy to our friend.
)"},
    {"Repossession", R"(
Franklin receives a call from Simeon
[Hard][Simeon]:    Franklin!
[Hard][Franklin]:    Eh, what's going down, homie?
[Easy][Simeon]:    The market, my boy. Liquidity's a bitch. Get over here so I can give you the new repo list.
[Hard][Franklin]:    Alright, I'll be around when I get a chance.

-If the repossessed car suffered heavy damage in the previous mission
[Normal][Franklin]:    Hey, what's going down, Simeon?
[Easy][Simeon]:    Franklin, I must ask you: the last car you repossessed, it was in a terrible state. Was that how you found it?
[Hard][Franklin]:    Uhh, yeah, man. The dude wrecked it.
[Normal][Simeon]:    Ah, that's all I need to know for the insurance men. Come to the dealership, I have something to show you.

Franklin walks into the showroom
[Normal][Franklin]:    Hey, what's up, Simeon?
[Easy][Simeon]:    My dear boy. So good to see you. So good. Hold me.
[Easy][Franklin]:    Yeah, look, man...Look, we've been working together for about a few months now, right?

Franklin and Simeon go into the office
[Easy][Simeon]:    Which is why I am very honored to announce to you, that you are Employee of the Month.
[Normal][Simeon]:    Anyway, congratulations! It wasn't easy picking a winner.
  One line split into 3:
[Easy][Franklin]:    Yeah, me, Lamar, your nephew Sacha with the twitch. 
[Normal][Franklin]:    Look, man. It's been a real honor, homie, but I gotta move forward in my life. 
[Easy][Franklin]:    It seem like all I do is let people tell me what to do and I do it and nothing changes.
[Easy][Simeon]:    I tell you what, my boy, you tell me exactly what you want, and I will very carefully explain to you why it cannot be.
  One line split into 2:
[Easy][Simeon]:    Today is repossessing vehicles that fools have purchased at exorbitant interest rates. 
[Easy][Simeon]:    But tomorrow - together! I never had a black son, but if I did I want him to be just like you.

Lamar interrupts the conversation
[Normal][Lamar]:    Knock-knock, niggas!
[Normal][Simeon]:    Hello, Lamar!
[Normal][Lamar]:    What's up, Simeon? What's up, homie? What's happening, homie?
[Extreme][Franklin]:    Sup, dog?
[Easy][Simeon]:    Franklin here has been awarded Employee of the Month.
[Normal][Lamar]:    You fucking with me, right?
[Normal][Franklin]:    Man, we both being fucked with, dog.
[Easy][Lamar]:    Man, knock it off, man. For real? After all the motherfucking work I put in, man?
[Easy][Franklin]:    Man, fuck this Employee of the Month shit, homie. I'm sitting up here trying to get us...
  One line split into 4:
[Easy][Lamar]:    What do you mean, "fuck this Employee of the Month shit", man? When there's some shit to be won, Goddamnit, I want it. 
[Normal][Lamar]:    I don't give a fuck what it is. Y'know what I'm talkin' about? I take no prisoners. 
[Normal][Lamar]:    I go hard doing this shit. Big dog. Big nuts. 
[Easy][Lamar]:    When names is on a motherfuckin' board, I want to see my name at the top of that motherfucker, and next to it, it needs to say "Winner".
[Normal][Simeon]:    Maybe next month, huh?
[Easy][Lamar]:    Man, fuck next month, Simeon. What about today? I... I demand a retrial.
[Easy][Simeon]:    Today is nothing, just a bike. Hasn't made a payment at all. Some kid at Vespucci Beach. His name is Esteban Jimenez.
[Normal][Franklin]:    Is he in a gang?
[Easy][Simeon]:    Curiously enough, I did not inquire when he bought the bike.
[Easy][Lamar]:    We got work to do, err... Employee of the Month.
[Extreme][Franklin]:    Man, fuck you, and come on.
[Easy][Lamar]:    Man, you's about a "yes, master"-ass nigga.

Franklin and Lamar leave the showroom
[Normal][Lamar]:    What we waiting for? Magellan Ave, nigga. Vespucci Beach.
[Normal][Lamar]:    Let's go to Vespucci. Magellan Ave.

-If Franklin retains his default hairstyle
[Easy][Lamar]:    So you still rollin' with that ol' raggedy-ass hair? That country bumpkin shit is enough to get us shot right there.
[Normal][Franklin]:    I never took you to be a ol' hair stylist-type bitch, but now it's all starting to make sense.

-If Franklin changed his hairstyle
[Normal][Lamar]:    At least you had that old raggedy-ass hair restyled, I was about to have to drop your ass.
[Hard][Franklin]:    Man, fuck you, nig, I wish I hadn't a' cut it.

The conversation in the car
[Normal][Franklin]:    Hey, wasn't that motherfucker who took the bike that ese - Vagos dude? With the tattoo on his face and shit?
[Extreme][Lamar]:    Yeah, that was him.
[Normal][Franklin]:    Fuck, homie, I don't want no unnecessary bullshit here, alright?
[Normal][Lamar]:    Nigga, I don't give a shit. There's a reason Simeon pays a couple of mean-looking motherfuckers to come repo this shit. We ain't girl scouts.
[Hard][Franklin]:    In your case, I ain't so sure about that.
[Normal][Lamar]:    Man, step up, nigga! Of course this dude real. Who else is gonna have the required surplus of paper, and deficiency of brain cells? He just put a dub down on this bike.
[Hard][Franklin]:    Twenty G's?
[Hard][Lamar]:    With a three-G note!
[Hard][Franklin]:    Damn, that motherfucker must be tricked out, dog.
[Normal][Lamar]:    Man, this whole setup designed to take drug money.
[Hard][Franklin]:    Alright, man, look, we go in quiet. In and out, no fuckin' drama.
[Normal][Lamar]:    I'll try, homie. But I'm one loud, dramatic, brash, crazy, greedy, shoot-a-motherfucker-in-the-back-type motherfucker. And you love me for it, nigga.
[Hard][Franklin]:    That's right, homie. Nothing but love, nigga.
[Normal][Lamar]:    That Simeon a funny dude though, huh? It's gonna be a shame when we get to book his ass and jack him for all this shit.
[Hard][Franklin]:    What the fuck you talking about? You a psychotic motherfucker.
  One line split into 2:
[Extreme][Lamar]:    That's how shit work, ain't it? You do some jobs for a fool, develop a little uneasy relationship, and then they ask you to do something above and beyond. 
[Extreme][Lamar]:    You fall out, fools get capped, then you start all over again with some other fool.
[Hard][Franklin]:    Where the fuck you get that from? That ain't my life, dummy.
[Extreme][Lamar]:    How 'bout the boy with the eye, from around the way? Marcus, or somethin'? You was slanging for him and then he got what was comin', right?
[Extreme][Franklin]:    That was different. That dude had it coming.
[Normal][Lamar]:    I don't wanna clap my boy Yetarian either, I like homie. This just smacks of the inevitable.
[Normal][Franklin]:    Look, dog, this time we legit, homie. This honest work, it's gonna end up with us coming up in the world.
[Hard][Lamar]:    Oh, really? That's a nice change from fools comin' up on us.
[Extreme][Franklin]:    That's trill, homie.
[Hard][Lamar]:    You damn right that's trill, partner, but it's a shame I don't believe it. You wanna drop some notes on that shit, I'll give you the odds, homie.
  One line split into 2:
[Hard][Franklin]:    You Apache motherfuckers love your bets, huh? 
[Extreme][Franklin]:    You should go work on one of them reservation casinos, only they'd kick yo' ass out for being a fradulent imposter, motherfucker.
[Hard][Lamar]:    You and all yo' little racial stereotypes and shit? I find 'em offensive. I'm very sensitive to your intolerance, my nigga.

Franklin and Lamar arrive at the complex in Vespucci Beach
[Easy][Lamar]:    The bike should be in one of the lockups down here.
[Easy][Franklin]:    “Should be” is the story of your life, asshole.

Franklin and Lamar jump the fence of the complex, and walk down the alleyway
[Hard][Lamar]:    I'ma make this look easy.
[Normal][Lamar]:    I think this crazy motherfucker want something. Hey, what's up homie, you alright?
[Normal][Lamar]:    Ungh! Yeah, you thought I was gonna hit yo' bitch-ass huh? Drunk-ass nigga.
[Hard][Lamar]:    Shit, man. Play it cool.
[Hard][Lamar]:    Be cool, nigga.
[Normal][Lamar]:    Yeah, that's right. Keep it moving, bitch.
[Normal][Franklin]:    Man, I don't like this shit one bit. Hey, look, let's keep it smooth, homie.
[Normal][Lamar]:    Man, your pussy the only thing that's smooth up in this shit.
[Normal][Franklin]:    Man, what exactly did I do in a past life to deserve your stupid ass?
[Normal][Lamar]:    This a routine lick, dog. Chill.
[Normal][Franklin]:    Do them Vagos look routine? This is Shady-Ass Alley!
[Hard][Lamar]:    Shit, we in Vespucci Beach.
[Hard][Franklin]:    We on the wrong side of Vespucci Beach. You should know, a block makes a difference.
[Extreme][Lamar]:    Eh, eh, eh, hold up.

Franklin and Lamar search the garages at the end of the alley
[Hard][Lamar]:    Got to be in one of these motherfuckers.
[Normal][Lamar]:    It's in one of these lock-ups.

-If Franklin searches the two smaller garages first
[Hard][Lamar]:    It got to be this other one. If that weren't it...
[Hard][Lamar]:    Ain't nowhere else it could be.

Franklin and Lamar open the biggest garage
[Easy][Lamar]:    Man, ain't this 'bout a bitch? Ain't no motherfucking bike in here, man.
[Extreme][Franklin]:    No shit, nigga.

A pair of Vagos walk up to Franklin and Lamar
[Normal][Lamar]:    Hola, ese.
[Normal][Lamar]:    Yeah? You saw this, motherfucker?

The fight between the Vagos and Franklin and Lamar
[Normal][Franklin]:    Hey, nigga. I woulda just gotten my ass beat over a fucking gun fight.
[Easy][Lamar]:    Man, stop being a pussy, nigga, and grab that heat.
[Hard][Lamar]:    Get in behind that truck, homie!
[Hard][Lamar]:    Find your bitch-ass some cover!
[Extreme][Franklin]:    So much for legit work.
[Hard][Franklin]:    You sure pick the right people to pick a fight with, nigga.
[Hard][Franklin]:    You make friends wherever your ass go, nigga.
[Normal][Lamar]:    Motherfuckers on the scaffold is on me. Shoot up that canister!
[Hard][Lamar]:    Now look what you have gone and done. Follow me, let's get through this!
[Hard][Lamar]:    Even this shit out, homie! Grab the shotgun!
[Hard][Lamar]:    Some more of them niggas.
[Hard][Lamar]:    Man, what's a few more of these motherfuckers?
[Hard][Lamar]:    Over there! They comin' out that door!
[Hard][Lamar]:    Check that door! They tryin' to mash on us!
[Normal][Lamar]:    Somebody tell them niggas this a legal repossession.
[Hard][Lamar]:    Damn, it's a gang of niggas out here. They got their whole hood with 'em!
[Extreme][Lamar]:    Up there! To the right!
[Hard][Lamar]:    Up there, shoot that nigga! Bust his ass!

During the shootout, a group of Vagos attempt to flee in a car
[Hard][Lamar]:    They tryin' to bail! Get that ride!
[Hard][Lamar]:    Shoot the gas, homie!
[Extreme][Lamar]:    Don't fuck with this pyromaniac motherfucker!
[Normal][Lamar]:    You still breathing, homie?
[Hard][Franklin]:    Yeah, barely, homie.
[Hard][Lamar]:    Shit, we gotta get the fuck away from this shit.
[Easy][Franklin]:    Man, we only came here for a bike.

The two spot Esteban Jimenez on the motorcycle, fleeing the scene
[Normal][Lamar]:    And there the motherfucker is right there. Hey, nigga, come here, we got yo' pink slip!
[Hard][Franklin]:    We really gonna repo after all this bullshit?

Franklin and Lamar hop in their car to pursue Jimenez
  Dialogue 1
[Hard][Franklin]:    You crazy motherfucker! Why we have to pop all them people?
[Hard][Lamar]:    You was there too. Correct me if I'm wrong, but you shot more of them than I did.
[Extreme][Franklin]:    Yeah, but you started this shit, stupid.
  Dialogue 2
[Normal][Lamar]:    Let's get him, homie! I wanna get paid!
[Normal][Franklin]:    Paid ain't worth shit when you doin' twenty-five with a L. We massacred those motherfuckers. Shit.

-If Jimenez is not in sight
  Dialogue 1
[Extreme][Lamar]:    Man, you lost him already!
[Normal][Franklin]:    That's a monster fucking bike he riding, stupid.
  Dialogue 2
[Hard][Lamar]:    This punk get away, we goin' down, homie. He gonna pin us for all these bodies.
[Hard][Franklin]:    And whose fault is that, Mr Eighties Action Movie Body-Countin' Motherfucker?
[Extreme][Lamar]:    Don't play the blame game, just get on this shit.
  Dialogue 3
[Extreme][Lamar]:    Motherfucker's gettin' away from us.
[Hard][Franklin]:    That's because he's sitting on a hundred and forty cubic inches right there, nigga.
[Extreme][Lamar]:    Oh shit, professor, you're right!

-If the duo catch up to Jimenez
[Hard][Lamar]:    Pop that fool. We need him on his ass so we can get what we came for.
[Normal][Lamar]:    We need to shoot him off the bike. Couple of scratches is better than nothin'.
[Normal][Lamar]:    We want your bike, bitch.
[Normal][Lamar]:    Time to give that shit up, you no-credit motherfucker!
[Normal][Lamar]:    That's the bike we came for!

Franklin and Lamar catch up to Jimenez and kill him
[Normal][Lamar]:    Take the bike and meet me at the car wash round the way.
[Normal][Lamar]:    Dog, we gotta lay low. Get the bike and meet me at the car wash on Innocence.

Franklin arrives at the car wash
[Easy][Franklin]:    Man, I can't hang with yo' ass for a while, bro. You a psychopath! You done finally fuckin' lost it!
[Easy][Lamar]:    Nigga, that's that Apache blood in me, homie. You lucky I ain't do a flying tomahawk and scalp they motherfuckin' ass.
[Easy][Franklin]:    We can't repo the assets of a dead man, “big sitting chief asshole”!
[Easy][Lamar]:    Nigga, and we ain't going to neither, nigga. I'm gonna keep this motherfucker for myself. Tell Simeon we couldn't recover it.
[Normal][Franklin]:    You fucking tell him, you fucking moron!
)"},
    {"The_Jewel_Store_Job", R"(
Smart Approach Beginning
The crew is looking over the plan
  One line split into 4:
[Normal][Michael]:    Now, we all know why we're here. We've got a store to take. The plan is simple... elegant.
[Hard][Michael]:    Listen to Lester, pay attention to the information he gives you and we'll all make a buck.
[Hard][Michael]:    Things go bad, you know the drill. This wasn't organized, we don't know each other.
[Hard][Michael]:    We got caught up in a robbery and acted in self-defense. But that's not going to be an issue, because everything's gonna go just fine.
  One line split into 2:
[Normal][Lester]:    The um... the err, alarm system is easy. Now if I didn't need to be running things I could have it offline myself no problem but uh, you should be able to get us a pretty decent window.
[Normal][Lester]:    How decent depends on the job you do. Now, once it's down, you signal Michael, he makes the call.
  One line split into 2:
[Easy][Michael]:    If things look good, we should be able to drop a present right through the air vent on the roof.
[Easy][Michael]:    Everybody goes to sleep, no problem, we take our time. If we run into trouble, we move quickly and with force. Any questions? No? Let's go.

-Depending on the chosen crew
[Hard][Michael]:    Frank, you're with me. Rickie, I hope you can manage the truck with the bikes.
[Hard][Michael]:    Frank, you're with me. Christian, take the truck with the bikes.
[Hard][Michael]:    Frank, you're with me. Paige, you're in the truck with the bikes.
[Hard][Michael]:    Toh, McReary, take the van.
[Hard][Michael]:    Eddie, Norm, you got the van.
[Hard][Michael]:    Gus, Eddie, you're in the van, alright?
[Hard][Michael]:    Packie and Karim - the van.
[Hard][Michael]:    Norm and Karim - you've got the van with Bugstar on the side of it.
[Hard][Michael]:    Gus, Karim, you got the van.

The crew leaves the garment factory
[Hard][Michael]:    See you on Little Portola, people. Initials only from here on out.
[Normal][Michael]:    Because you use too much gas on these guys, you'll kill 'em.
[Extreme][Franklin]:    Well, shit, don't blame me the way these canisters is mixed.
[Hard][Michael]:    Listen, I've stuck my neck out for you here.
[Hard][Franklin]:    Man, you don't need to tell me that shit again.
[Normal][Michael]:    I got faith in you, F, but you're unproven.
[Normal][Franklin]:    Unproven? For real? So I didn't prove myself when I jumped off the back of that yacht on the highway, huh?
[Normal][Michael]:    Yeah, but these guys don't know you. They see some gangbanger with a happy trigger finger. They got money and their freedom on the line.
[Hard][Franklin]:    I ain't gonna fuck this up, man.
[Extreme][Michael]:    Good. I got enough shit to worry about.

-If Eddie, Patrick, Gustavo, and Paige were chosen
[Normal][Michael]:    I don't know. I ain't done any real work in years, you know, so I'm giving half the take to guys who're supposed to be the best in the business...
[Hard][Franklin]:    Alright, then it's all taken care of. You on top of shit.
[Easy][Michael]:    Yeah, do I need to give 12% to a gunman? 14% to a driver? 15 to a hacker? And that's on top of all the other outlays! I feel like a chump buying myself a score.
[Hard][Franklin]:    Shit. I guess we'll find out if they worth it, right?

-If Karim, Norm and Rickie/Christian were chosen
[Hard][Franklin]:    Eh, uhh, so you made savings on the personnel, huh?
[Hard][Michael]:    Yeah, well, I figure they're on Lester's list of potentials, they can't be that bad.
[Extreme][Franklin]:    Sure, man, what could go wrong?
[Hard][Michael]:    A cheap hacker, a cheap driver, a cheap gunman? Ugh, pretty much everything can go wrong.
[Hard][Michael]:    Great. The novice is reassuring me. Oh, brother.

-If Eddie, Norm and Rickie/Christian were chosen
[Hard][Franklin]:    So you cut corners on the quality of the crew, huh?
[Hard][Michael]:    I allocated the resources the way I saw fit, okay?
[Hard][Michael]:    The driver's capable. The others - not so much.
[Hard][Franklin]:    So, that's like, what? Gunman and hacker?
[Hard][Michael]:    Yeah. The getaway should be fine, but we gotta hope these two hold it together during the robbery.
 
-If Karim, Patrick/Gustavo and Paige were chosen
[Hard][Franklin]:    What's fucking with you, man?
[Hard][Michael]:    I'm going over things in my head, you know. I mean, I laid out for a gunman and a hacker, but the driver I chose ain't getting much of a share.
[Hard][Franklin]:    Shit, if you worried about underpaying people, man, worry about underpaying me.
[Hard][Michael]:    Hey, you got to work your way up to a decent cut, kid. These guys are being paid what they're worth, based on past performances, I guess.
[Hard][Franklin]:    But the driver's performances weren't really that hot? Great.
[Hard][Michael]:    Listen, he got us bikes today, and he'll be leading you out of the area, so I'm hoping he's undervalued.

-If Eddie, Patrick/Gustavo and Rickie/Christian were chosen
[Hard][Franklin]:    The crew? Man, they looked like serious people, homie.
[Hard][Michael]:    I made a saving on the hacker, but that shouldn't matter if I do my job on the shop floor.
[Hard][Franklin]:    But the rest of them are serious, right? The gunman and the driver?
[Hard][Michael]:    Yeah, they're serious. They're taking a serious cut. They better be fucking worth it.

-If Karim, Norm and Paige were chosen
[Hard][Franklin]:    Look, man, if you're nervous about being back at work, you sure don't show it.
[Hard][Michael]:    Not so much being back at work, but the people I'm back at work with... present company excepted.
[Hard][Michael]:    Yeah, pretty low rent. I shelled out for a good hacker, so we should have some time inside the store...
[Hard][Michael]:    But the guy I'm in there with ain't dependable, and the guy in charge of the getaway, he ain't either.

-If Eddie, Norm and Paige were chosen
[Hard][Franklin]:    Hey, Mike, you worried? Did you pick the wrong people to come along on this?
  One line split into 2:
[Hard][Michael]:    Remains to be seen. We'll have a good driver waiting outside with bikes, and they'll lead you out of there. 
[Hard][Michael]:    The hacker should earn their pay check by getting us longer inside, but the gun, ehh, questionable.
[Hard][Franklin]:    Well, everyone in the store's going to be out. You won't need no crowd control.
[Hard][Michael]:    Maybe, but they're still part of the team. They cost us, I'll regret it.

-If Karim, Patrick/Gustavo and Rickie/Christian were chosen
[Hard][Franklin]:    So what kind of people we working with, man?
[Hard][Michael]:    Don't worry about the crew, worry about yourself.
[Hard][Franklin]:    Look, homie, Imma look after my shit, it's just I'm curious.
[Hard][Michael]:    Well, the guy coming inside with me is tough. The driver and hacker, they ain't so good, but, you know, how much of Madrazo's money am I meant to give away, huh?
[Hard][Michael]:    Yeah, we'll find out just how reasonable in a couple of hours...

The 2 arrive at the construction site and Franklin gets to the roof
[Normal][Michael]:    Alright, this is it up there. There's a way through the site up to the roof.
[Hard][Franklin]:    Man we went over this. I'm cool.
[Easy][Michael]:    Alright, when the gas is in the ventilation system, give us the word.
[Hard][Franklin]:    Excuse me. Exterminator. Hey, there ain't no one around.
[Hard][Michael]:    That suits us. Come on, get up to the roof.
[Hard][Michael]:    We're in position, waiting on your signal.
[Hard][Franklin]:    Just got to get where I can throw this.

-If frag grenades are equipped
[Hard][Michael]:    Hey, I saw you had some grenades on you. Don't throw them instead of the gas bombs.
[Hard][Franklin]:    I think I can tell the difference.

Frankling throws in the gas grenade.
[Hard][Franklin]:    Get in there. That was it. They going out.

Loud Approach Beginning
The crew is looking over the plan
  One line split into 3:
[Easy][Michael]:    Alright, I want to say thanks for being a part of our little operation. We're all professionals, we all know the score. 
[Normal][Michael]:    We're gonna execute the plan, we're gonna move quick, and we're gonna keep cool. 
[Easy][Michael]:    Anybody gets pinched, this meeting never took place. We don't know each other, is that clear?
  One line split into 2:
[Hard][Lester]:    Now, we've, uh, looked very, very carefully at the plans. 
[Normal][Lester]:    We considered something more complicated, but given the location, the weakness of staffing and the exit points, we believe that a more simple plan will work best.
  One line split into 5:
[Normal][Michael]:    We're gonna hack in, disable security, and waltz right in through the front door. 
[Normal][Michael]:    Security guard should be to our left. We neutralize him, 15 seconds later, you come in. 
[Easy][Michael]:    I want extreme pressure applied to the staff, the customers are to be calmly subdued. 
[Easy][Michael]:    I want one guy on crowd control, while you and I empty out the merchandise from the cabinets. 
[Easy][Michael]:    We're in and out in 90 seconds, guys. Franklin'll handle your getaway, I'm leaving on foot. Any questions?

Everyone leaves the garment factory
-Depending on the chosen crew.
[Hard][Michael]:    Rickie, I hope you can manage the truck with the bikes. Other three, you're riding with me.
[Hard][Michael]:    Christian, take the truck with the bikes. Rest of you, you're with me.
[Hard][Michael]:    Paige, you're in the truck with the bikes. Everyone else with me.
[Hard][Michael]:    Franklin's driving the van. Toh and McReary, you're in the back. I'm taking the passenger seat.
[Hard][Michael]:    Alright, Frank's got the wheel. Eddie and Norm are in the back, I'm sitting up front.
[Hard][Michael]:    Gus, Eddie, I need you in the back of the van. Franklin's driving, I'm in the passenger seat.
[Hard][Michael]:    Packie, Karim - you're in the back of the van, Franklin'll be driving us, and I'll be riding shotgun.
[Hard][Michael]:    Franklin - you're driving the van. Norm, Karim - you're in the back, I'm up front, alright?
[Hard][Michael]:    Gus, Karim, you're riding in the back of the van, I'm passenger. Franklin, driving.

The crew drives to the store
  One line split into 6:
[Easy][Michael]:    Alright, listen up. The four of us in this van - we're about to become accomplices in a major crime.
[Normal][Michael]:    I gotta be able to trust you with my life, my liberty, my reputation. Same goes the other way.
[Normal][Michael]:    A crew will only work - only work - when there's trust.
[Normal][Michael]:    So, in the interest of fostering that type of relationship in the short time that we've got, let me introduce myself.
[Easy][Michael]:    I'm Michael, I've done this type of thing before, more than a few times. And I've made good money doing it, enough to spend a long time not doing it.
[Easy][Michael]:    I hope it goes without saying, I know a lot of people. Anyone yaps, about me or any of you, you'll be dealt with. Got it? Good. Now, Frank, over to you.
  One line split into 3:
[Easy][Franklin]:    Uhhh... yeah, man, I'm Franklin, dog, and, um, I'm new to these planned out detailed robberies.
[Normal][Franklin]:    I done my share of small jobs, you know - liquor stores, warehouses, boosting cars.
[Easy][Franklin]:    And then I met this dude right here, Michael, man, and he turned me onto this thing.
  One line split into 5:
[Easy][Packie]:    Packie McReary, from the fine borough of Dukes in God's own Liberty City. 
[Hard][Packie]:    I came to LS seeking fame and fortune and I found boredom and idiots. 
[Hard][Packie]:    If you wanna hear about my old life, well, you're the first people I met out here who do. 
[Hard][Packie]:    Everyone talks about what they're gonna do, who they're gonna be, they don't talk about who they are, and they don't care about anyone else. 
[Hard][Packie]:    It's a city full of cokeheads who ain't on coke. I swear, they put something in that kale juice.
[Normal][Michael]:    Uh, Packie comes to us highly recommended.
[Extreme][Packie]:    Damn straight I do. Let's clean these assholes out!
[Hard][Norm]:    Michael De Santa - formerly Michael Townley, right? Can I just say, you're the reason I got in the game, man. You're my inspiration, the original outlaw.
[Hard][Michael]:    I don't know what you're talking about, so stop talking.
[Extreme][Norm]:    Uhh, be cool, man. Your secret's safe with me... us.
  One line split into 2:
[Easy][Gustavo]:    I'm Gustavo, Gus Mota, I'm from East Los, know what I'm saying? Used to bang for the Vagos, but hey, don't tell them I told you that, I'ma need them homies if I go away. 
[Hard][Gustavo]:    I guess I found out pretty young I could pull a trigger... but it was a couple of years before I started doing it for bread, know what I'm saying? Instead of that reppin' where you from bullshit. And here we are.
[Normal][Michael]:    Uhh, alright, and this is Eddie Toh. He'll be cleaning out the cabinets and handling the getaway. He's got you some bikes for that. All you need to know about him is he's good.
[Normal][Michael]:    Uhh, so, yeah. this is Karim Denz. He's cleaning out the cabinets and taking charge of the getaway. I think it's fair to say you're kinda new to this, right? But I think he can handle it.

They exit the van and storm into the store
[Normal][Michael]:    Go get the bikes. Let's go. Ready?
[Easy][Michael]:    Ladies and gentlemen, this is your moment! Please, don't make me ruin all the great work your plastic surgeons have been doing. On the floor, now!

-Depending on the chosen driver
[Hard][Eddie]:    I'll clean out these displays! I'm on the display cases!
[Hard][Karim]:    I'm on the cases! I got these cases!

-Depending on the chosen hacker
[Hard][Rickie]:    Bros, I wouldn't stay in there too long, okay? This alarm is gonna go... at some point.
[Normal][Michael]:    You gotta be kidding me! Why did I employ a hacker who can't run anti-virus software?
[Hard][Rickie]:    Shit, ummmm, okay. The alarm hasn't gone off yet.
[Hard][Christian]:    I've bought you some time. You've got just over a minute before the alarm's back online.
[Normal][Michael]:    That's all I get for 10%? Bullshit.
[Hard][Paige]:    I've been able to get you around a minute and a half before the alarm'll reset itself.
[Normal][Michael]:    90 seconds? Alright, that's why we pay you what we do. Hey, we got more than enough time to clean these people out. Let's do it!

-Depending on the chosen gunman
[Hard][Packie]:    This one's done! The cleaner's coming in! Smash and grab, boys! Come on! Come on! Better not be the display model! I'm leaving 'em empty! Fuck yeah, come on! These guys got stock! We going big!
[Hard][Norm]:    Screw this, man. This crap's slippery. Who made this shit so small? Get in there, shit! Screw these rich pricks. It don't matter if we lose some, right? These hands weren't built for delicate work. This is a classy joint!
[Hard][Gustavo]:    How we doing, how we doing? How you doing over there? They got nice stones in this joint. Let's go! Let's go! This better not be paste.

-Depending on the chosen crew
[Normal][Michael]:    Quick hands, man, that's why you get your cut. Keep it up. Keep moving quick, you're doing great.
[Normal][Michael]:    Hey, buddy, you keep handling the merch like that, you're gonna earn your 12%.
[Normal][Michael]:    Hey, can you get your shit together and stop dropping loot?!

-If Michael stops the guard from escaping
[Extreme][Michael]:    Don't be a hero!
[Hard][Michael]:    I know you ain't the best, N, but you gotta do better! Control 'em.
[Hard][Michael]:    N, get your shit together, and be better than your quote tells me you are.

-If Michael doesn't stop the guard from escaping
[Hard][Michael]:    Ohh, you're supposed to be controlling the crowd.

-If a good gunman was chosen
[Hard][Packie]:    No, don't even try it! Get on the ground! Girl, where are you going? Get on the floor!
[Hard][Gustavo]:    On the floor, lady! On the fucking floor! You, lady, get on the fucking floor!
[Normal][Michael]:    Good crowd work, P! You were worth the outlay.
[Normal][Michael]:    G, nice work on the crowd! You're worth whatever we're paying you, buddy.

-If Norm was chosen
[Hard][Michael]:    Lady! Stop or you're dead! Hey, lady, you wanna get killed?! Stop right there!

-Depending on the chosen driver
[Normal][Michael]:    Nice work, man. There's a reason you're paid what you're paid.
[Hard][Michael]:    Hey! Can you get your shit together and stop dropping loot? Hey, asshole! Most of your cut is sittin' on the fucking floor!
[Hard][Eddie]:    Quick hands! My wife would like it here!
[Hard][Karim]:    This is tricky work! This ain't as easy as it looks! Someone pick that up! I'm paid to drive, not do this!

From here on the same between loud and smart
-If there's a low amount of time left. Depending on the chosen hacker
[Hard][Rickie]:    I think you got maybe thirty seconds left.
[Hard][Paige]:    Forty seconds.
[Hard][Michael]:    Alright, we're running out of time. We got to step it up if we're gonna hit the target.
[Hard][Michael]:    Keep it up, keep moving quick, you're doing great.
[Hard][Michael]:    Time's running out. Take what you can!

The required amount of jewels are taken
[Normal][Michael]:    Hey! We hit our target! Let's see how high we can go! 
[Normal][Michael]:    Alright, that's our target. Keep it up, see how much we can get! We're almost out of here!

-If all jewels were taken
[Normal][Michael]:    They're outta stones, let's hit the road!
[Extreme][Michael]:    Ain't nothing left here for us! Let's get!
[Extreme][Michael]:    Yeah, baby! We got it all. Let's go, let's go!

-If the alarm hasn't gone off yet
[Hard][Franklin]:    Coast is clear. If we move now, man, it'll be a clean getaway.

-If not all jewels were taken and time runs out
[Extreme][Michael]:    Time's up. We gotta go.

-Depending on the chosen hacker
[Hard][Rickie]:    Dudes, you gotta go, you gotta go! Get out of there, guys. I'm so not designed for a penitentiary. I hate cock!
[Hard][Christian]:    The cops are on the way! You need to... ahh... get outta there!
[Hard][Paige]:    The cops are coming. You've been warned.
[Normal][Franklin]:    Eh, the cops are round the corner, man. Let's do this.
[Normal][Franklin]:    Eh, I'm starting to hear cop noises. We got to get moving.

Leaving the store
[Extreme][Franklin]:    Man, get the fuck out my face!
[Easy][Michael]:    You forget a thousand things every day, pal. Make sure this is one of 'em. I'll see you at the river. Go!

-If Michael doesn't leave the store in time. Depending on the chosen hacker
[Hard][Rickie]:    Shit, ummmm, get outta there!
[Hard][Christian]:    Police have been dispatched. We're t-talking seconds here!
[Hard][Paige]:    Get out of there now, or you will arrested and imprisoned. Go!

-Depending on the chosen driver
[Hard][Eddie]:    Stay close, stay safe, let's go! Stay on me, across here! Let's go!
[Hard][Karim]:    Map says this way, boys, alright? Stick to me, people. Here we go!
[Normal][Franklin]:    I could do with some directions, Karim! I'm driving blind back here! 
[Hard][Franklin]:    I could do with some damn warnings before we turn! 
[Hard][Franklin]:    If there's a turn coming up, you gotta tell us, man! 
[Normal][Franklin]:    Karim, you're the driver, shit, where we going? 
[Hard][Franklin]:    Hey, ain't the driver meant to be telling us where to go?!

The 3 flee from the police on bikes
[Hard][Eddie]:    Hard left here, going onto the big road, Dorset Drive.
[Hard][Eddie]:    We're taking a right here, and dropping off a bridge onto the freeway.
[Hard][Eddie]:    Now we duck to the right into these tunnels.
[Extreme][Franklin]:    Headlights on now.
[Extreme][Franklin]:    Put your headlights on, it's dark in here.

-If Norm was chosen
[Extreme][Norm]:    It's going out from under me!
[Hard][Norm]:    My bike's spazzing out!
[Normal][Franklin]:    G crashed his bike, man, that's what happens when you're workin' with fools.
[Normal][Franklin]:    Damn cheap-ass crew crashed his self out.
[Hard][Eddie]:    He was an amateur. Guy was a fool.
[Hard][Karim]:    He was more experienced than me! I guess we're all learning on the job!

-If Eddie was chosen
[Hard][Eddie]:    We're going through this tunnel up ahead.
[Hard][Eddie]:    We should be able to get into a tunnel just here.
[Hard][Eddie]:    The tunnel splits. Both lead into the same place.
[Hard][Eddie]:    The tunnel diverges, but it'll converge in a second.
[Hard][Eddie]:    It gets muddy, just keep going.
[Hard][Eddie]:    Keep going through the mud, bike should be able to handle it.
[Hard][Eddie]:    If you know the route and you're not an idiot, these are the only bikes you'd choose.
[Hard][Eddie]:    I studied the route and I'm not an idiot - these are the best bikes for the terrain.
[Hard][Eddie]:    Don't go down the tunnels here. Take a left, go up by the escalators.
[Hard][Eddie]:    Go across the metro tracks, take a left and go up the escalators.
[Hard][Eddie]:    Down the corridor, we'll go into the sewer.
[Hard][Eddie]:    This should take us into the sewer system.
[Hard][Eddie]:    There's a drop here.
[Hard][Eddie]:    Hitting a drop.
[Hard][Eddie]:    Bear left here, and hard left when you're through the gate.
[Hard][Eddie]:    There's a gate on the left, take a left once you're through it.
[Hard][Eddie]:    We should start climbing toward the surface. This is the home straight.
[Hard][Eddie]:    We're going to start ascending. This means we're nearly out of here.
[Hard][Eddie]:    Daylight, here we go.
[Hard][Eddie]:    I see light, we're out.

-If Patrick was chosen
[Hard][Packie]:    I didn't know why we had dirt bikes, now I see this dirt, I understand.
[Hard][Packie]:    Good thing we got bikes that can handle the dirt.
[Hard][Gus]:    Good call on the bikes! We need 'em on this ground.

-If Karim was chosen
[Hard][Karim]:    Okay, uhh, keep going through here.
[Hard][Karim]:    Keep going, okay. Yeah.
[Hard][Karim]:    Shit, man, there's a split, I dunno...
[Hard][Karim]:    Uhh, I didn't know about this split up here.
[Hard][Karim]:    If I'd known about the mud, I mighta chose a different bike.
[Hard][Karim]:    What the fuck? My bike don't like this mud.
[Normal][Franklin]:    Eh, Karim, these the wrong bikes to be using down here - couldn't you have got us some scramblers?
[Normal][Franklin]:    Eh, these sports bikes ain't handling the mud - you shoulda got some scramblers, man.
[Hard][Karim]:    You asked for bikes, I got fast bikes! No one said scramblers.
[Hard][Karim]:    I picked these for speed - no one told me about the mud!
[Hard][Karim]:    I don't know where the fuck we're going.
[Hard][Karim]:    I hope I'm guessing right!
[Hard][Karim]:    Oh, crap. What the fuck is this?
[Hard][Karim]:    Through here - maybe!
[Hard][Karim]:    I can't take much more of this! The truck better be here!
[Hard][Karim]:    There's a way out - I don't know if it's the right way out!
[Hard][Karim]:    I hope this is the exit we're after!

-If Karim was chosen and gunman died
[Hard][Karim]:    I don't know where to go... you gotta hold on. Hold on, I've lost my bearings...
[Normal][Franklin]:    You're lost? Man, you kidding me?! Where'd Michael find you?
[Normal][Franklin]:    You know you been employed as a driver? Man, you're supposed to know where you going.
[Hard][Karim]:    Wait, it was... ummmmm...
[Hard][Karim]:    Wait, I'll figure it out.
[Hard][Karim]:    Screw it, we go this way.
[Hard][Karim]:    Let's try this way!
[Normal][Franklin]:    You better be right.
 
-Depending on the chosen hacker
[Hard][Rickie]:    Uhh, bros? Just to warn you, we're not the only people waiting for you in the LS River.
[Hard][Rickie]:    Dudes, we're here, and it, ahh, looks like the cops might know where you're coming out the sewer.
[Hard][Christian]:    L-look out, guys. The police know your exit point. They're right here in the river.
[Hard][Christian]:    Word of warning - cops are waiting for you in the LS River. We'll try to help.
[Hard][Paige]:    Bike team - the plan hasn't worked - cops are waiting for you in the LS River - we're here, but be ready.
[Hard][Paige]:    The police know where you're coming out in the river - we're here to help, but get ready for a warm welcome.

The crew meets in the LS river and continue the chase
[Extreme][Michael]:    Hang in there, boys, I got this covered.
[Easy][Michael]:    Keep driving - the bullbars on this truck should help us with the cops!
[Easy][Michael]:    Hang in there, boys! I got bullbars on the truck -I'll make short work of these cops.
[Normal][Michael]:    Keep going - I'll get to work on the cops with these bullbars.
[Easy][Franklin]:    Look there, roadblock! Cut to the left bank of the river!
[Easy][Franklin]:    Hey dude, the river's shallow! Cross over this side!
[Easy][Franklin]:    Roadblocks up ahead, man. We should cut across the river!

-Depending on the chosen hacker
[Hard][Rickie]:    You mind if I video tape this? It is insane.
[Hard][Rickie]:    This shizz be intense, yo.
[Hard][Rickie]:    Hey, it wouldn't be a robbery without a car chase, bro.
[Hard][Christian]:    I-I-I should have stayed at my machine!
[Hard][Christian]:    I think I'm gonna hurl.
[Hard][Christian]:    Are we gonna make it?
[Hard][Paige]:    I should charge more for getting involved in police chases.
[Hard][Paige]:    Typical men, can't organise anything without a big showdown with the law.
[Hard][Paige]:    I can shoot if I have to, tell me if I'm needed.
[Hard][Paige]:    If you need another gun, gimme the word.

[Hard][Michael]:    Backup's here, watch your ass
[Hard][Franklin]:    Serious, man, we can't take much more of this!
[Hard][Franklin]:    Dude, we can't take any more of this, come on!
[Easy][Franklin]:    M, dude, this is it. The bike's goin' give out!

-Depending on the chosen driver
[Hard][Eddie]:    Help me out here - I got a wife and kids!
[Hard][Karim]:    You lose me, you lose the rocks!

[Normal][Franklin]:    Back across the other side, right!

-Depending on the chosen hacker and if a good gunner was chosen
[Hard][Rickie]:    No more cherry tops, bro. We are clear.
[Hard][Rickie]:    High fives, bro. We lost 'em.
[Hard][Christian]:    I think we're clear of the cops.
[Hard][Christian]:    I think that's all of them. Shit.
[Hard][Paige]:    It looks good to me. Fine work, boss.
[Hard][Paige]:    No cops in the area - I think we got a chance.

[Easy][Michael]:    Alright, we're clear of the cops for right now. Let's stop at the end of the river, and we'll get the bikes into the truck.
[Easy][Michael]:    Alright, we got a window. Let's stop at the end of the river, get the bikes in the truck.

-If Norm was chosen
[Normal][Michael]:    Two bikes?! What the hell happened?
[Easy][Franklin]:    Man, dude crashed bike before he got in the tunnels.
[Normal][Michael]:    Ah, shit, I shoulda paid for a better gunman. What happened to his part of the score?
-Bag Retrieved
[Normal][Franklin]:    I managed to pick it up.
-Bag Not Retrieved
[Normal][Franklin]:    It's with his crashed out bike.

The crew loads the bikes into the truck and drives to Lester
[Normal][Michael]:    F, come on, get in.
[Easy][Michael]:    Lester's around the corner at the lockup.
[Easy][Franklin]:    Aw, fuck, man. I thought I was goin' be stuck to that bike.
[Easy][Michael]:    Yeah, I thought you were gonna get stuck under a cop car.
[Normal][Franklin]:    There gotta be more dudes waiting round that way. We did not just get away with that shit, did we?
[Normal][Michael]:    You know what? I think we did.
[Normal][Michael]:    Oh yeah! We did it, baby! We did it!

-Depending on the chosen gunman
[Hard][Packie]:    It is good to be alive! I'm doing some rails tonight!
[Hard][Gustavo]:    All in a day's work, homies.

-Depending on the chosen driver
[Hard][Eddie]:    Whoa, one step closer to retirement! Whoa, I might just be able to send my kids to college!
[Hard][Karim]:    You guys gotta join my herd. Whoo, what kinda social media you guys on?

-Depending on the chosen hacker
[Hard][Rickie]:    Holla! I think I found my new calling, bros! When L.I. fired me, they said I was dangerous - they was right, yo!
[Hard][Paige]:    I won't say it went off without a hitch, but it went off. It was a good takedown - here's to the first of many.

Michael parks the truck
[Easy][Michael]:    Call your gem guy, Lesty baby, 'cause we got merchandise!
[Normal][Michael]:    Alright, people. We need to split up, they're gonna be looking for a crew.
[Easy][Lester]:    I'll wire your cuts when the rocks have been sold.
[Normal][Franklin]:    That shit was crazy, dog. So what now?
[Normal][Lester]:    We get out of here, keep our heads down.
[Easy][Michael]:    Hey, you did it good, kid. What'd I tell you, Lester, huh?
  One line split into 2:
[Easy][Michael]:    Alright, look, everybody take off. Hey, Franklin, listen, Lester and I got some things we gotta clean up. 
[Normal][Michael]:    I want you to stop by the house a little later on, we'll celebrate, alright?
[Normal][Michael]:    Oh man, we're back in action.
 
Franklin receives a phone call from Tanisha
[Normal][Tanisha]:    I don't care if you got money now. Don't you get it? That ain't what I was looking for - not then, not now, not ever.
[Normal][Franklin]:    I know it ain't important, just let me take you somewhere nice, a'ight?
[Normal][Tanisha]:    Where are you? A-are you in a strip club? Grow up, stop looking for the easy way!
[Normal][Franklin]:    Tanisha, I got to go, a'ight? I'ma change, I promise, you won't even recognize me.
)"},
    {"The_Long_Stretch", R"(
Franklin arrives at his house
[Hard][Magenta]:    Oooh, all our prayers have been answered...Weeeeeell... hello.
[Extreme][Franklin]:    I don't wanna know.
[Normal][Franklin]:    What the fuck? I mean what the hell going on here?
[Normal][Denise]:    Wait a minute, Franklin. What are you doing here?
[Easy][Franklin]:    I live here. This half my house, too.
[Easy][Denise]:    So you say. Anyway, Magenta is reinvigorating my femininity. So make yourself scarce, boy. Go. Go.

Franklin leaves his house
[Normal][Denise]:    And stay out of trouble!
[Extreme][Magenta]:    Vulva. Vulva. Vulva.
[Hard][Lamar]:    I'm like, "Bitch, you ain't no more of a man than me."
[Easy][Lamar]:    Gangsta shit, nigga. Look who's biz-ack!
[Hard][Lamar]:    What's happenin' with it, man?

The conversation between the 3
[Normal][Stretch]:    Oh, no, no, show some respect here, nigga. The man they couldn't hold down is back. Come on now.
[Normal][Franklin]:    Damn, man, I gotta spend my day with another middle-aged fool trying to recapture his youth?
[Hard][Stretch]:    What this fool just say?
[Normal][Franklin]:    I missed you, dog.
[Normal][Stretch]:    Oh, oh, you miss me, huh?
  One line split into 2:
[Normal][Franklin]:    Nah, I ain't missed you. Your ass could have stayed gone for good. 
[Easy][Franklin]:    So I fucked your girl, mugged your moms, and better yet, I ain't thought about your ass in years.
[Normal][Stretch]:    Haha, you got jokes now, huh? Hey, but I see you doing well for yourself, check that on out.
[Hard][Franklin]:    Shit, I'm doing just fine.
[Normal][Stretch]:    That's what I hear. But I know some sweet boys up in the pen that got bigger balls than you.
[Normal][Franklin]:    Oh, you been doing your time looking at sweet boy balls?
[Hard][Franklin]:    Yeah, it's good to have confirmation.
[Normal][Stretch]:    This funny fuck... Why you keep hanging around this clown, L? Shake this fool, man.
[Easy][Lamar]:    We from the same set, Stretch. Why, why y'all niggas can't get along? You all been doing this shit for years, man.
[Normal][Franklin]:    You know what, dog, it's good you back home. Glad you here. Missed you, boy. Man... you definitely got hit up inside.
[Extreme][Stretch]:    Hit up?!
  One line split into 2:
[Hard][Stretch]:    Yo, motherfucker. I know little niggas like you been turned out on the daily. 
[Normal][Stretch]:    Talking about being hit up, nigga, I swear, man. You ain't got no motherfucking respect.
[Normal][Franklin]:    Motherfucker, I got respect for reality.
[Normal][Stretch]:    Reality? Alright, alright, you keep thinking that. Just keep thinking that, nigga. Shit, you gon' er get yours.
[Normal][Lamar]:    Striz-etch, come on, cool out, chill, man.
[Normal][Stretch]:    Whoa, whoa, whoa... What the fuck, man? This motherfucker get on my Goddamn nerves.
[Normal][Lamar]:    The nigga get on my nerves too, man. P... Part of the nigga charm, man. F, come on, man, let's just bust a move, man. You gonna drive or what, pimp?
[Extreme][Franklin]:    Drive where?
[Normal][Lamar]:    Pick up this heat, nigga.
[Easy][Lamar]:    Business, nigga.
[Easy][Lamar]:    Business. Come on, y'all niggas act like girls.

The 3 get into the car
[Hard][Stretch]:    Let's go to the gun store.
[Hard][Stretch]:    Ammu-Nation. Come on. Let's go.

They drive to Ammu-Nation
-If Franklin retains his default hairstyle
[Hard][Lamar]:    Shit, homie. You gonna drop all that bread on that gear, you might as well get a haircut too.
[Extreme][Stretch]:    Fuckin' crazy haired microphone motherfucker.
[Hard][Franklin]:    I got a microphone I can shove right in your prison pocket. Nigga, you walk like you keistering shit anyway.

-If Franklin changes his hairstyle and clothes
[Normal][Lamar]:    Man, look at this fly ass motherfucker for a minute. Check him out!
[Hard][Stretch]:    Haha. He got his swag on, right? I hope he don't think he gonna fuck us. 'Cause he looking pretty, but I ain't goin' the distance, homie.
[Hard][Franklin]:    Stretch, you got your fucking nerves given your history. You the creepiest motherfucker around here, nigga.
  One line split into 2:
[Hard][Stretch]:    You know, when I went away, you punks was little homies, and I was a big homie. 
[Hard][Stretch]:    Now I'm out, and you little homies is big homies, but you still got to respect.
[Hard][Franklin]:    Man, what the fuck this nigga talking about?
[Hard][Lamar]:    We all big homies, but he bigger, right?
[Hard][Franklin]:    Man, that's some fucking pyramid scheme bullshit.
[Easy][Lamar]:    Pyramids is good, man! Illuminati pharaoh shit.

They arrive at Ammu-Nation
[Normal][Lamar]:    Soon as we get this shit, soon as we get paid, homie.
[Hard][Franklin]:    Soon as we incarcerated is more likely.
[Normal][Lamar]:    Oh, hell yeah. You could trick your blam-blam out up in here.
[Hard][Stretch]:    Quit all that, just straight up artillery man. Alright?
[Normal][Franklin]:    Man, would y'all shut the fuck up? I got this, you clowns.

-If Franklin doesn't own a shotgun
[Easy][Lamar]:    Ooh, homie. Get the shotty with the flashlight on it.

-If Franklin owns a shotgun
[Easy][Lamar]:    Alright, homie. Get your shotgun with the flashlight modification.

-If Franklin already has a flashlight on the shotgun
[Normal][Lamar]:    Alright homie, get some heat.

[Hard][Franklin]:    Why the fuck am I the only one buying this?
[Hard][Stretch]:    'Cause we got sheets, homie. Now shut the fuck up and come on.

  Dialogue 1
[Normal][Stretch]:    Hey, listen up. I want to be crystal fucking clear, nothing he buying got anything to do with us.
[Normal][Lamar]:    Yeah you know, uh, we got felonies, and we ain't touchin' shit.
  Dialogue 2
[Hard][Stretch]:    Whoo, it's hot as hell up in here, homie.
[Hard][Stretch]:    We could buy this shit, go to Mexico. Take that sit to the bank.
[Normal][Lamar]:    Hell no, nigga we... We got felonies, nigga, ain't nobody doin' that shit. We legit as a motherfucker on this right now man, just chill.
  Dialogue 3
[Hard][Stretch]:    Now, how the hell you work in a shop like this all day long, without feeling the need to grab a gun, just walk out the door and shoot somebody?
[Hard][Franklin]:    I think they do a psych test to make sure people working here don't do shit like that.
[Hard][Lamar]:    Man, you see this nigga right here, he look every bit of fifty-one fifty.

-If Franklin doesn't have enough cash
[Hard][Lamar]:    Oh you flat, homie? I would think you was flendin', but ain't no fiends that fat. Take this cheese, you old broke ass bitch.

-If Franklin purchased shotgun without flashlight
  One line split into 2:
[Normal][Stretch]:    You supposed to get a flashlight before you book.
[Normal][Stretch]:    Hey, get back in here and get the flashlight.

Franklin purchases the shotgun with the flashlight
[Hard][Lamar]:    Man, we got some recycling to do. Come on, man. Center off Fringe in La Puerta.
[Hard][Lamar]:    Take us down to that one spot where the base heads be takin' their cans at. You know, on Fringe in La Puerta.

They drive to the recycling plant
[Hard][Franklin]:    You got some cans or some shit I don't know about?
[Normal][Lamar]:    Nah, homie. We got ourselves a drug deal.
[Normal][Franklin]:    Why do I get the feeling this gonna be one of them deals gone wrong type situations?
[Normal][Stretch]:    Now, see, that's that negative attitude Lamar was telling me about, nigga. You ain't gettin' nowhere thinking like that.
[Normal][Franklin]:    The power of positive bullshit. You oughta be clenching your motherfucking vagina muscles with my aunt, nigga.
[Extreme][Lamar]:    After his bit, it probably need tightening up.
[Hard][Stretch]:    This ain't new age shit, it's fact. You get what you give, fool.
[Hard][Franklin]:    You've been getting dick, but you aint giving it, huh?
[Normal][Stretch]:    Some mark talk like that to an OG? Huh, CGF has changed, man. No wonder the hood is so lame right now.
[Hard][Franklin]:    Speaking of change. Lamar's been meaning to talk to you, homie.
[Hard][Lamar]:    It's nothing, my nigga, nothing. You know, just some ideas, that's all.
[Hard][Stretch]:    Man, ideas ain't your strong suit. So put it on me.
[Hard][Lamar]:    It's nothing real, homie. When it's something real, we'll talk.
[Hard][Franklin]:    Bullshit, man. It's realer than this crap.

They arrive at the recycling plant and enter it
[Hard][Lamar]:    Alright homie, we meeting in here.
[Normal][Franklin]:    Man, how'd you find this place?
[Hard][Lamar]:    Homie set it up.
[Hard][Stretch]:    This the kind of spot where we ain't goin' be disturbed.
[Extreme][Franklin]:    That's what the fuck worries me. I'm more of a hide in plain sight type of nigga.
[Hard][Stretch]:    No. You more of a punk bitch type nigga.

The scene with D
[Normal][Lamar]:    We got that shit, nigga! Where the paper at, nigga? I'm talkin' about beaucoup bills, boy.
[Normal][D]:    Lamar Davis, wassup, boy? Everything cool?
[Easy][Franklin]:    Hold on, man. What the fuck, man? You was just kidnappin' this nigga!
[Normal][Lamar]:    Oh, come on! You know real recognize real.
[Easy][Stretch]:    D, my nigga! Just got out. Crossing lines. Did some time with some of your folk.
[Normal][D]:    Uh... Hey, hey, hey. Look, look, look. This ain't about you, man.
[Hard][D]:    You know these niggas done fucked up!
[Normal][Stretch]:    What the fuck this trick talkin' about man?
[Extreme][D]:    Yeah, yeah, yeah, yeah! Ah ha.
[Normal][D]:    See, see, they puttin' a nigga on TV, man!
[Hard][Stretch]:    Somebody creepin' on us?!
[Normal][D]:    About some gang intervention shit.
[Easy][Franklin]:    Hey, this ain't the police, dog! This some Ballas bullshit!
[Normal][Franklin]:    Hey, we were set up, nigga!
[Normal][Stretch]:    Ol' bitch-ass Ballas!

They fight the Ballas
[Normal][Lamar]:    Fuckin' D! He set us up!
[Hard][Franklin]:    Fuck! I said lay low after you got clocked.
[Hard][Lamar]:    You lay low, motherfucker. That ain't me.
[Hard][Lamar]:    You handled that fool!
[Hard][Stretch]:    Yeah, and I'd handle him again! Many times as it takes! Shit!
[Hard][Franklin]:    Shit nigga, then we all be dead.
[Normal][Stretch]:    Snitch-ass fool thought we was marks!
[Hard][Lamar]:    Now he ain't thinking shit!

The fire starts
[Hard][Stretch]:    The place on fire! Shit's burning!
[Hard][Stretch]:    You see that shit!? It's on fire, man!
[Hard][Stretch]:    Fire, dog! Fire! You see that shit!?
[Hard][Franklin]:    Well, move! Shit, we gotta go before this shit spreads!

They arrive at Franklin's house
[Easy][Lamar]:    Here we are, man. You go hang with your auntie while the men break it off.
[Easy][Lamar]:    Hell nah, nigga. You sounding more and more like a sni-i-itch every day.
[Normal][Franklin]:    Nah, nigga. I sound like somebody trying to make some paper and not get killed.
[Normal][Stretch]:    He's a hook ass nigga. I told you.
[Easy][Franklin]:    Nigga, go toss a salad! Stretch mark-ass bitch!
)"},
    {"Pulling_Favors", R"(
Franklin approaches Tonya
[Easy][Franklin]:    What the fuck is wrong with you, Tonya?
[Easy][Tonya]:    Ain't nothing wrong with me, nigga. Shit!
[Normal][Franklin]:    Well, your ass don't look too good. Where the fuck is JB?
[Extreme][Tonya]:    Smoking.
[Normal][Tonya]:    Well, y'know, I quit. Y'know what I'm sayin'? Almost...
  One line split into 3:
[Easy][Tonya]:    JB... look, JB gonna lose everything. 
[Easy][Tonya]:    He gonna lose the house, y'know what I'm sayin'? The business, everything and you his cousin, nigga. 
[Hard][Tonya]:    You said you was gonna help.
[Hard][Franklin]:    He ain't my cousin.
[Hard][Tonya]:    Whatever, if that's how you feel...
[Normal][Franklin]:    What the fuck do I know about towing cars?
[Easy][Tonya]:    Look, it's easy. If JB can do it, you can do it, for fuck's sake. Come on. I'ma show you. Come on. Shit.
[Hard][Tonya]:    Shit... I gotta show him everything.
[Normal][Franklin]:    Hey, look, let's make this quick. I got shit to do.
[Easy][Tonya]:    Nigga, you need to slow it down, Tanisha was right.

Franklin and Tonya enter a vehicle
[Extreme][Franklin]:    A'ight, shit, where we goin'?
[Normal][Tonya]:    Truck's at the Davis Sheriff impound.
[Normal][Franklin]:    Oh, man. How did I get dragged into this?
[Easy][Tonya]:    We both know you always been sweet on me, shit, Franklin Clinton.
[Normal][Franklin]:    Shit, your ass must be high or something.
  One line split into 2:
[Normal][Tonya]:    I told you, I don't do that shit no more. 
[Easy][Tonya]:    I mean, I baby-dose now and again, just for the taste, but I'm doin' good, boo, your eyes don't lie.
[Normal][Franklin]:    Whatever you say, girl. Come on.

They arrive at the impound and enter the truck
[Easy][Tonya]:    There's JB's truck. Let's go bring the cha-ching, homie.
[Easy][Tonya]:    Yo, we on that like ugly on your momma.
[Easy][Tonya]:    It's Tonya, fool, and my boy Franklin. We fillin' in for JB.
[Hard][Tonya]:    A bucket. This one should be easy.
[Normal][Franklin]:    Shit. Not easy enough for JB to drag his ass outta whatever crackhouse he's laying in.
[Normal][Tonya]:    His loss, your gain, sugar.
[Normal][Franklin]:    Except I ain't gainin' shit. Sugar.
[Normal][Tonya]:    Move that seat back and you know I'll make it right for you.
[Easy][Franklin]:    That ain't what I'm sayin'. Damn, Tonya, what the fuck happened to you?

They reach the abandoned car and hook it up
  One line split into 3:
[Normal][Tonya]:    Okay, I seen JB do this a hundred times. 
[Easy][Tonya]:    Back up close, make sure the hook is down, and it should slide right in. 
[Normal][Tonya]:    A'ight, baby, back it up nice and steady.
[Normal][Tonya]:    Okay, we are in, baby. Let's get this back to the lot.
[Hard][Franklin]:    Man, this was not how I saw my day going.
[Normal][Tonya]:    So I ain't seen you around the hood much?
[Normal][Franklin]:    I been tryin' to branch out, can't stay in Chamberlain Hills forever.
[Normal][Tonya]:    Ooh, nigga got airs now. I remember you before you was a wannabe, when you just was.
[Normal][Franklin]:    And I remember you and JB before y'all was dopeheads. Shit changes.
[Normal][Tonya]:    You the one all turfed up. JB smokin', but he ain't smokin' homies. He out here grindin', towin' cars, payin' bills.
[Easy][Franklin]:    For real? ‘Cause I could have sworn it was me out here towin' cars for him.
[Normal][Tonya]:    And lookin' damn fine doin' it too, baby.

They pull into the impound and drop the car off
  One line split into 2:
[Normal][Tonya]:    Okay, we make the drop where they got the areas marked. 
[Normal][Tonya]:    They get real finicky when we don't leave it in the right place.
[Easy][Tonya]:    I'll see you on the block. Anything you need, you holler at me. Now, where is that fool?
)"},
};
