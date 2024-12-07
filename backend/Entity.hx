package backend;

import backend.GlobalData;

public abstract class Entity {
    private var name: UnicodeString;
    // combat vars
    public var maxHealth(default, null): Int;
    public var health(default, null): Int;
    public var stamina(default, null): Int;
    public var physAtk(default, null): Int;
    public var physDef(default, null): Int;
    public var magAtk(default, null): Int;
    public var magDef(default, null): Int;

    public var dead: Bool = false;

    // private var actionList = haxe.ds.List<Action>();

    // check vars
    private var strength: Int;
    private var agility: Int;
    private var wisdom: Int;
    private var charisma: Int; 

    // create instance of given entity
    public function new(entity: EntityStats){ // create in global data
        name = entity.name;
        health = entity.health;
        stamina = entity.stamina;
        physAtk = entity.physAtk;
        physDef = physDef.physAtk;
        magAtk = entity.magAtk;
        magDef = entity.magDef;

        strength = entity.strength;
        agility = entity.agility;
        wisdom = entity.wisdom;
        charisma = entity.charisma;
    }

    public function DamageEntity(amount: Int, phys: Bool): Void{
        // chance to dodge based on agility, exits the function

        if(physAtk){
            health = health - (amount - physDef);
        }
        else{ // if magic damage
            health = health - (amount - magDef);
        }

        if(health < 0){
            health = 0;
        }
    }

    public function HealEntity(amount: Int, phys: Bool): Void{
        health += amount;

        if(health > maxHealth){
            health = maxHealth;
        }
    }
}

public class EntityStats{
    var name: UnicodeString;
    var health: Int;
    var stamina: Int;
    var physAtk: Int;
    var physDef: Int;
    var magAtk: Int;
    var magDef: Int;

    var strength: Int;
    var agility: Int;
    var wisdom: Int;
    var charisma: Int;
}