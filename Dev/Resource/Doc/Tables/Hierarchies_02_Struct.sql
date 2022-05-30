/*
 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for Hierarchies
-- ----------------------------
DROP TABLE IF EXISTS "Hierarchies";
CREATE TABLE "Hierarchies" (
  "Rec" INTEGER PRIMARY KEY AUTOINCREMENT,
  "TId" INTEGER NOT NULL DEFAULT 0,
  "Ext" INTEGER NOT NULL DEFAULT 0,
  "NId" INTEGER NOT NULL DEFAULT 0,
  "Idx" INTEGER NOT NULL DEFAULT 0,
  "FId" INTEGER NOT NULL DEFAULT 0,
  "Lft" INTEGER NOT NULL DEFAULT 0,
  "Rgt" INTEGER NOT NULL DEFAULT 0,
  "Lev" INTEGER NOT NULL DEFAULT 0,
  "Cnt" INTEGER NOT NULL DEFAULT 0
);

-- ----------------------------
-- Auto increment value for Hierarchies
-- ----------------------------

PRAGMA foreign_keys = true;
