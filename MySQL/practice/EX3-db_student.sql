/*
Navicat MySQL Data Transfer

Source Server         : yhy
Source Server Version : 50527
Source Host           : localhost:3306
Source Database       : db_student

Target Server Type    : MYSQL
Target Server Version : 50527
File Encoding         : 65001

Date: 2019-10-22 08:40:52
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `course`
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
  `cno` char(10) NOT NULL,
  `cname` varchar(20) NOT NULL,
  `ccredit` smallint(6) DEFAULT NULL,
  `semster` smallint(6) DEFAULT NULL,
  `period` smallint(6) DEFAULT NULL,
  PRIMARY KEY (`cno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO course VALUES ('C01', '计算机导论', '3', '1', '3');
INSERT INTO course VALUES ('C02', 'VB', '4', '3', '4');
INSERT INTO course VALUES ('C03', '计算机网络', '4', '7', '4');
INSERT INTO course VALUES ('C04', '数据库基础', '6', '6', '4');
INSERT INTO course VALUES ('C05', '高等数学', '8', '1', '8');

-- ----------------------------
-- Table structure for `sc`
-- ----------------------------
DROP TABLE IF EXISTS `sc`;
CREATE TABLE `sc` (
  `sno` char(7) NOT NULL,
  `cno` char(10) NOT NULL,
  `grade` smallint(6) DEFAULT NULL,
  PRIMARY KEY (`sno`,`cno`),
  KEY `cno` (`cno`),
  CONSTRAINT `sc_ibfk_1` FOREIGN KEY (`sno`) REFERENCES `student` (`sno`) ON UPDATE CASCADE,
  CONSTRAINT `sc_ibfk_2` FOREIGN KEY (`cno`) REFERENCES `course` (`cno`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of sc
-- ----------------------------
INSERT INTO sc VALUES ('9512101', 'C01', null);
INSERT INTO sc VALUES ('9512101', 'C02', '87');
INSERT INTO sc VALUES ('9512101', 'C03', '95');
INSERT INTO sc VALUES ('9512101', 'C04', '76');
INSERT INTO sc VALUES ('9512101', 'C05', '80');
INSERT INTO sc VALUES ('9512103', 'C03', '51');
INSERT INTO sc VALUES ('9512103', 'C05', null);
INSERT INTO sc VALUES ('9521101', 'C05', null);
INSERT INTO sc VALUES ('9521102', 'C05', '80');
INSERT INTO sc VALUES ('9521103', 'C01', '80');
INSERT INTO sc VALUES ('9521103', 'C05', '45');
INSERT INTO sc VALUES ('9531101', 'C01', '67');
INSERT INTO sc VALUES ('9531101', 'C05', '81');
INSERT INTO sc VALUES ('9531102', 'C01', null);
INSERT INTO sc VALUES ('9531102', 'C05', '94');

-- ----------------------------
-- Table structure for `student`
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `sno` char(7) NOT NULL,
  `sname` char(10) NOT NULL,
  `ssex` char(2) DEFAULT NULL,
  `sage` tinyint(3) unsigned DEFAULT NULL,
  `sdept` varchar(20) DEFAULT '计算机系',
  PRIMARY KEY (`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO student VALUES ('9512101', '李勇', '男', '19', '计算机系');
INSERT INTO student VALUES ('9512103', '王敏', '女', '20', '计算机系');
INSERT INTO student VALUES ('9521101', '张莉', '女', '22', '信息系');
INSERT INTO student VALUES ('9521102', '吴宾', '男', '21', '信息系');
INSERT INTO student VALUES ('9521103', '张海', '男', '20', '信息系');
INSERT INTO student VALUES ('9531101', '钱小平', '女', '18', '数学系');
INSERT INTO student VALUES ('9531102', '王大力', '男', '19', '数学系');
INSERT INTO student VALUES ('9541101', 'test', '女', '20', '计算机系');
