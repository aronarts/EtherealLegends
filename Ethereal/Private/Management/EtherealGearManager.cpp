// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"

#include "Gear/Magic/Spells/Cure.h"
#include "Gear/Magic/Spells/CureII.h"
#include "Gear/Magic/Spells/Regen.h"
#include "Gear/Magic/Spells/Refresh.h"
#include "Gear/Magic/Spells/Blizzard.h"
#include "Gear/Magic/Spells/Thunder.h"
#include "Gear/Magic/Spells/Fire.h"
#include "Gear/Magic/Spells/Berserk.h"
#include "Gear/Magic/Spells/Barrier.h"
#include "Gear/Magic/Spells/Haste.h"
#include "Gear/Magic/Spells/Dash.h"

#include "Gear/Weapons/OneHanded/IronSword.h"
#include "Gear/Weapons/OneHanded/Joyeuse.h"
#include "Gear/Weapons/OneHanded/Hauteclaire.h"
#include "Gear/Weapons/OneHanded/Excalibur.h"
#include "Gear/Weapons/OneHanded/BalloonSword.h"
#include "Gear/Weapons/OneHanded/BeamSaber.h"

#include "Gear/Weapons/OneHanded/Shields/Aegis.h"
#include "Gear/Weapons/OneHanded/Shields/DiablosDread.h"
#include "Gear/Weapons/OneHanded/Shields/SpartanShield.h"
#include "Gear/Weapons/OneHanded/Shields/WarAspis.h"

#include "Gear/Weapons/Ranged/ShortBow.h"
#include "Gear/Weapons/Ranged/EagleEye.h"
#include "Gear/Weapons/Ranged/EurytosBow.h"
#include "Gear/Weapons/Ranged/Annihilator.h"

#include "Gear/Weapons/Ranged/Ammo/DemonArrow.h"
#include "Gear/Weapons/Ranged/Ammo/FlameArrow.h"
#include "Gear/Weapons/Ranged/Ammo/IronArrow.h"
#include "Gear/Weapons/Ranged/Ammo/WoodenArrow.h"

#include "Gear/Weapons/TwoHanded/Marauder.h"
#include "Gear/Weapons/TwoHanded/Juggernaut.h"
#include "Gear/Weapons/TwoHanded/Claymore.h"
#include "Gear/Weapons/TwoHanded/Temperance.h"

#include "Gear/Weapons/Casting/MagicOrbs.h"

#include "Gear/Items/Consumable/Potion.h"
#include "Gear/Items/Consumable/HiPotion.h"
#include "Gear/Items/Consumable/Ether.h"
#include "Gear/Items/Consumable/HiEther.h"
#include "Gear/Items/Consumable/Reraise.h"
#include "Gear/Items/Consumable/Elixer.h"
#include "Gear/Items/Consumable/Adrenaline.h"
#include "Gear/Items/Consumable/SentinelBrew.h"

#include "Gear/Armor/Head/ClothCap.h"
#include "Gear/Armor/Head/AdamanHelm.h"
#include "Gear/Armor/Head/WarHelm.h"
#include "Gear/Armor/Head/ValhallaHelm.h"

#include "Gear/Armor/Cape/ClothCape.h"
#include "Gear/Armor/Cape/KnightsCape.h"
#include "Gear/Armor/Cape/ThiefsShroud.h"
#include "Gear/Armor/Cape/RestoreCloak.h"

#include "Gear/Armor/Body/ClothTunic.h"
#include "Gear/Armor/Body/AdamanCuirass.h"
#include "Gear/Armor/Body/WarCoat.h"
#include "Gear/Armor/Body/ValhallaBreastplate.h"

#include "Gear/Armor/Hand/ClothGloves.h"
#include "Gear/Armor/Hand/AdamanGauntlets.h"
#include "Gear/Armor/Hand/WarGloves.h"
#include "Gear/Armor/Hand/ValhallaGauntlets.h"

#include "Gear/Armor/Legs/ClothPants.h"
#include "Gear/Armor/Legs/AdamanCuisses.h"
#include "Gear/Armor/Legs/WarBrais.h"
#include "Gear/Armor/Legs/ValhallaFlanchard.h"

#include "Gear/Armor/Ring/SilverRing.h"
#include "Gear/Armor/Ring/DarksteelRing.h"
#include "Gear/Armor/Ring/ShadowRing.h"
#include "Gear/Armor/Ring/RestoreRing.h"

#include "Gear/Armor/Feet/ClothShoes.h"
#include "Gear/Armor/Feet/AdamanSabatons.h"
#include "Gear/Armor/Feet/WarBoots.h"
#include "Gear/Armor/Feet/ValhallaGreaves.h"

#include "EtherealGearManager.h"

// Sets default values
AEtherealGearManager::AEtherealGearManager()
{

}

// Creates a Gear Item, when given a name
AEtherealGearMaster* AEtherealGearManager::CreateGear(EMasterGearList ItemToCreate)
{
	AEtherealGearMaster* Item = nullptr; // set a false item

	UWorld* World = GetWorld();

	if (World)
	{
		switch (ItemToCreate)  // This switch will run through and spawn a piece of Gear based on the name
		{
		case EMasterGearList::GL_None:
			// Do nothing, because the item is set to NONE!
			break;

			///////////////////////////////
			// MAGIC

		case EMasterGearList::GL_Cure:
			Item = World->SpawnActor<ACure>();
			break;
		case EMasterGearList::GL_Cure2:
			Item = World->SpawnActor<ACureII>();
			break;
		case EMasterGearList::GL_Raise:
			// Do nothing, because Raise does not yet exist
			break;
		case EMasterGearList::GL_Regen:
			Item = World->SpawnActor<ARegen>();
			break;
		case EMasterGearList::GL_Refresh:
			Item = World->SpawnActor<ARefresh>();
			break;
		case EMasterGearList::GL_Esuna:
			// Do nothing, because Esuna does not yet exist
			break;
		case EMasterGearList::GL_Comet:
			// Do nothing, because Comet does not yet exist
			break;
		case EMasterGearList::GL_Blizzard:
			Item = World->SpawnActor<ABlizzard>();
			break;
		case EMasterGearList::GL_Thunder:
			Item = World->SpawnActor<AThunder>();
			break;
		case EMasterGearList::GL_Fire:
			Item = World->SpawnActor<AFire>();
			break;
		case EMasterGearList::GL_Poison:
			// Do nothing, because Poison does not yet exist
			break;
		case EMasterGearList::GL_Sleep:
			// Do nothing, because Sleep does not yet exist
			break;
		case EMasterGearList::GL_Berserk:
			Item = World->SpawnActor<ABerserk>();
			break;
		case EMasterGearList::GL_Barrier:
			Item = World->SpawnActor<ABarrier>();
			break;
		case EMasterGearList::GL_Haste:
			Item = World->SpawnActor<AHaste>();
			break;
		case EMasterGearList::GL_Slow:
			// Do nothing, because Slow does not yet exist
			break;
		case EMasterGearList::GL_Counter:
			// Do nothing, because Counter does not yet exist
			break;
		case EMasterGearList::GL_Stun:
			// Do nothing, because Stun does not yet exist
			break;
		case EMasterGearList::GL_Dash:
			Item = World->SpawnActor<ADash>();
			break;
		case EMasterGearList::GL_Gravity:
			// Do nothing, because Gravity does not yet exist
			break;

			///////////////////////////////
			// ONE-HANDED

		case EMasterGearList::GL_IronSword:
			Item = World->SpawnActor<AIronSword>();
			break;
		case EMasterGearList::GL_Joyeuse:
			Item = World->SpawnActor<AJoyeuse>();
			break;
		case EMasterGearList::GL_Hauteclaire:
			Item = World->SpawnActor<AHauteclaire>();
			break;
		case EMasterGearList::GL_Excalibur:
			Item = World->SpawnActor<AExcalibur>();
			break;
		case EMasterGearList::GL_BalloonSword:
			Item = World->SpawnActor<ABalloonSword>();
			break;
		case EMasterGearList::GL_BeamSaber:
			Item = World->SpawnActor<ABeamSaber>();
			break;

			///////////////////////////////
			// SHIELDS

		case EMasterGearList::GL_WarAspis:
			Item = World->SpawnActor<AWarAspis>();
			break;
		case EMasterGearList::GL_SpartanShield:
			Item = World->SpawnActor<ASpartanShield>();
			break;
		case EMasterGearList::GL_DiablosDread:
			Item = World->SpawnActor<ADiablosDread>();
			break;
		case EMasterGearList::GL_Aegis:
			Item = World->SpawnActor<AAegis>();
			break;

			///////////////////////////////
			// RANGED

		case EMasterGearList::GL_ShortBow:
			Item = World->SpawnActor<AShortBow>();
			break;
		case EMasterGearList::GL_EagleEye:
			Item = World->SpawnActor<AEagleEye>();
			break;
		case EMasterGearList::GL_EurytosBow:
			Item = World->SpawnActor<AEurytosBow>();
			break;
		case EMasterGearList::GL_Annihilator:
			Item = World->SpawnActor<AAnnihilator>();
			break;

			///////////////////////////////
			// AMMUNITION

		case EMasterGearList::GL_DemonArrow:
			Item = World->SpawnActor<ADemonArrow>();
			break;
		case EMasterGearList::GL_FlameArrow:
			Item = World->SpawnActor<AFlameArrow>();
			break;
		case EMasterGearList::GL_IronArrow:
			Item = World->SpawnActor<AIronArrow>();
			break;
		case EMasterGearList::GL_WoodenArrow:
			Item = World->SpawnActor<AWoodenArrow>();
			break;

			///////////////////////////////
			// TWO-HANDED

		case EMasterGearList::GL_Juggernaut:
			Item = World->SpawnActor<AJuggernaut>();
			break;
		case EMasterGearList::GL_Claymore:
			Item = World->SpawnActor<AClaymore>();
			break;
		case EMasterGearList::GL_Marauder:
			Item = World->SpawnActor<AMarauder>();
			break;
		case EMasterGearList::GL_Temperance:
			Item = World->SpawnActor<ATemperance>();
			break;

			///////////////////////////////
			// CASTING ORBS

		case EMasterGearList::GL_MagicOrbs:
			Item = World->SpawnActor<AMagicOrbs>();
			break;

			///////////////////////////////
			// CONSUMABLE ITEMS

		case EMasterGearList::GL_Potion:
			Item = World->SpawnActor<APotion>();
			break;
		case EMasterGearList::GL_HiPotion:
			Item = World->SpawnActor<AHiPotion>();
			break;
		case EMasterGearList::GL_Ether:
			Item = World->SpawnActor<AEther>();
			break;
		case EMasterGearList::GL_HiEther:
			Item = World->SpawnActor<AHiEther>();
			break;
		case EMasterGearList::GL_Elixer:
			Item = World->SpawnActor<AElixer>();
			break;
		case EMasterGearList::GL_Reraise:
			Item = World->SpawnActor<AReraise>();
			break;
		case EMasterGearList::GL_Adrenaline:
			Item = World->SpawnActor<AAdrenaline>();
			break;
		case EMasterGearList::GL_SentinelBrew:
			Item = World->SpawnActor<ASentinelBrew>();
			break;

			///////////////////////////////
			// ARMOR - HEAD
		case EMasterGearList::GL_ClothCap:
			Item = World->SpawnActor<AClothCap>();
			break;
		case EMasterGearList::GL_AdamanHelm:
			Item = World->SpawnActor<AAdamanHelm>();
			break;
		case EMasterGearList::GL_WarHelm:
			Item = World->SpawnActor<AWarHelm>();
			break;
		case EMasterGearList::GL_ValhallaHelm:
			Item = World->SpawnActor<AValhallaHelm>();
			break;

			///////////////////////////////
			// ARMOR - CAPE
		case EMasterGearList::GL_ClothCape:
			Item = World->SpawnActor<AClothCape>();
			break;
		case EMasterGearList::GL_KnightsCape:
			Item = World->SpawnActor<AKnightsCape>();
			break;
		case EMasterGearList::GL_ThiefsShroud:
			Item = World->SpawnActor<AThiefsShroud>();
			break;
		case EMasterGearList::GL_RestoreCloak:
			Item = World->SpawnActor<ARestoreCloak>();
			break;

			///////////////////////////////
			// ARMOR - BODY
		case EMasterGearList::GL_ClothTunic:
			Item = World->SpawnActor<AClothTunic>();
			break;
		case EMasterGearList::GL_AdamanCuirass:
			Item = World->SpawnActor<AAdamanCuirass>();
			break;
		case EMasterGearList::GL_WarCoat:
			Item = World->SpawnActor<AWarCoat>();
			break;
		case EMasterGearList::GL_ValhallaBreastplate:
			Item = World->SpawnActor<AValhallaBreastplate>();
			break;

			//////////////////////////////
			// ARMOR - HANDS
		case EMasterGearList::GL_ClothGloves:
			Item = World->SpawnActor<AClothGloves>();
			break;
		case EMasterGearList::GL_AdamanGauntlets:
			Item = World->SpawnActor<AAdamanGauntlets>();
			break;
		case EMasterGearList::GL_WarGloves:
			Item = World->SpawnActor<AWarGloves>();
			break;
		case EMasterGearList::GL_ValhallaGauntlets:
			Item = World->SpawnActor<AValhallaGauntlets>();
			break;

			///////////////////////////////
			// ARMOR - LEGS
		case EMasterGearList::GL_ClothPants:
			Item = World->SpawnActor<AClothPants>();
			break;
		case EMasterGearList::GL_AdamanCuisses:
			Item = World->SpawnActor<AAdamanCuisses>();
			break;
		case EMasterGearList::GL_WarBrais:
			Item = World->SpawnActor<AWarBrais>();
			break;
		case EMasterGearList::GL_ValhallaFlanchard:
			Item = World->SpawnActor<AValhallaFlanchard>();
			break;

			///////////////////////////////
			// ARMOR - RING
		case EMasterGearList::GL_SilverRing:
			Item = World->SpawnActor<ASilverRing>();
			break;
		case EMasterGearList::GL_DarksteelRing:
			Item = World->SpawnActor<ADarksteelRing>();
			break;
		case EMasterGearList::GL_ShadowRing:
			Item = World->SpawnActor<AShadowRing>();
			break;
		case EMasterGearList::GL_RestoreRing:
			Item = World->SpawnActor<ARestoreRing>();
			break;

			///////////////////////////////
			// ARMOR - FEET
		case EMasterGearList::GL_ClothShoes:
			Item = World->SpawnActor<AClothShoes>();
			break;
		case EMasterGearList::GL_AdamanSabatons:
			Item = World->SpawnActor<AAdamanSabatons>();
			break;
		case EMasterGearList::GL_WarBoots:
			Item = World->SpawnActor<AWarBoots>();
			break;
		case EMasterGearList::GL_ValhallaGreaves:
			Item = World->SpawnActor<AValhallaGreaves>();
			break;
		}
	}	

	//////////////////////////////
	// END
	return Item;
}