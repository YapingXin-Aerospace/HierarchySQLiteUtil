/*
 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001
 
 uint32_t Rec;
 uint16_t TId;
 uint16_t Ext;
 
 uint32_t NId;
 uint32_t Idx;
 
 uint32_t FId;
 uint32_t Lft;
 uint32_t Rgt;
 uint32_t Lev;
 uint32_t Cnt;
 
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for Hierarchies
-- ----------------------------
DROP TABLE IF EXISTS "Hierarchies";
CREATE TABLE "Hierarchies" (
  Rec INTEGER PRIMARY KEY AUTOINCREMENT,
  TId INTEGER NOT NULL DEFAULT 0,
  Ext INTEGER NOT NULL DEFAULT 0,
  NId INTEGER NOT NULL DEFAULT 0,
  Idx INTEGER NOT NULL DEFAULT 0,
  FId INTEGER NOT NULL DEFAULT 0,
  Lft INTEGER NOT NULL DEFAULT 0,
  Rgt INTEGER NOT NULL DEFAULT 0,
  Lev INTEGER NOT NULL DEFAULT 0,
  Cnt INTEGER NOT NULL DEFAULT 0
);

PRAGMA foreign_keys = true;
