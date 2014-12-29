item_db: (
//  Items Database
//
/******************************************************************************
 ************* Entry structure ************************************************
 ******************************************************************************
{
	// =================== Mandatory fields ===============================
	Id: ID                        (int)
	AegisName: "Aegis_Name"       (string)
	Name: "Item Name"             (string)
	// =================== Optional fields ================================
	Type: Item Type               (int, defaults to 3 = etc item)
	Buy: Buy Price                (int, defaults to Sell * 2)
	Sell: Sell Price              (int, defaults to Buy / 2)
	Weight: Item Weight           (int, defaults to 0)
	Atk: Attack                   (int, defaults to 0)
	Matk: Magical Attack          (int, defaults to 0, ignored in pre-re)
	Def: Defense                  (int, defaults to 0)
	Range: Attack Range           (int, defaults to 0)
	Slots: Slots                  (int, defaults to 0)
	Job: Job mask                 (int, defaults to all jobs = 0xFFFFFFFF)
	Upper: Upper mask             (int, defaults to any = 0x3f)
	Gender: Gender                (int, defaults to both = 2)
	Loc: Equip location           (int, required value for equipment)
	WeaponLv: Weapon Level        (int, defaults to 0)
	EquipLv: Equip required level (int, defaults to 0)
	EquipLv: [min, max]           (alternative syntax with min / max level)
	Refine: Refineable            (boolean, defaults to true)
	View: View ID                 (int, defaults to 0)
	BindOnEquip: true/false       (boolean, defaults to false)
	BuyingStore: true/false       (boolean, defaults to false)
	Delay: Delay to use item      (int, defaults to 0)
	FloorLifeTime: Delay to remove item from ground (int, default flooritem_lifetime)
	KeepAfterUse: true/false      (boolean, defaults to false)
	Trade: {                      (defaults to no restrictions)
		override: GroupID             (int, defaults to 100)
		nodrop: true/false            (boolean, defaults to false)
		notrade: true/false           (boolean, defaults to false)
		partneroverride: true/false   (boolean, defaults to false)
		noselltonpc: true/false       (boolean, defaults to false)
		nocart: true/false            (boolean, defaults to false)
		nostorage: true/false         (boolean, defaults to false)
		nogstorage: true/false        (boolean, defaults to false)
		nomail: true/false            (boolean, defaults to false)
		noauction: true/false         (boolean, defaults to false)
		nodelonuse: true/false        (boolean, defaults to false)
	}
	Nouse: {                      (defaults to no restrictions)
		override: GroupID             (int, defaults to 100)
		sitting: true/false           (boolean, defaults to false)
	}
	Stack: [amount, type]         (int, defaults to 0)
	Sprite: SpriteID              (int, defaults to 0)
	Script: <"
		Script
		(it can be multi-line)
	">
	OnEquipScript: <" OnEquip Script (can also be multi-line) ">
	OnUnequipScript: <" OnUnequip Script (can also be multi-line) ">
},
******************************************************************************/

