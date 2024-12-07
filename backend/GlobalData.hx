package backend;

import backend.Entity;

class GlobalData {
  static var initialised: Bool;
  public static var rooms(default, null): Array<Room>;
  
  var demonStats: EntityStats = {name: "Demon", 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  var demonEnemy: Entity = new Entity(demonStats);

  public static function Init(newRooms: Array<Room>): Void {
    if (initialised) {
      return;
    }

    rooms = newRooms;
  }

  public static function Log(): Void {
    // Sys.print("Room {}");
    for (room in rooms) {
      Sys.print(room.type + ", " + room.x + ", " + room.y + "\n");
    }
  }
}
