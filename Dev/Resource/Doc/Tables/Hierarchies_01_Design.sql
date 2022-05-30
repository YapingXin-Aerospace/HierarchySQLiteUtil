/*
 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001
 
 uint32_t Rec;
 uint16_t TId; // 表号
 uint16_t Ext; // 表号扩展标识
 
 uint32_t NId; // 节点编号
 uint32_t Idx; // 节点索引
 
 uint32_t FId; // 父Id
 uint32_t Lft; // 左值
 uint32_t Rgt; // 右值
 uint32_t Lev; // 层级(从1开始)
 uint32_t Cnt; // 直接下级数量
 
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
