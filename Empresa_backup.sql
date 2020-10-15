-- MySQL dump 10.11
--
-- Host: localhost    Database: Empresa
-- ------------------------------------------------------
-- Server version	5.0.38-Ubuntu_0ubuntu1.4-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `DEPARTMENT`
--

DROP TABLE IF EXISTS `DEPARTMENT`;
CREATE TABLE `DEPARTMENT` (
  `Number` int(11) NOT NULL auto_increment,
  `Name` varchar(45) NOT NULL,
  `Location` varchar(255) default NULL,
  PRIMARY KEY  (`Number`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `DEPARTMENT`
--

LOCK TABLES `DEPARTMENT` WRITE;
/*!40000 ALTER TABLE `DEPARTMENT` DISABLE KEYS */;
INSERT INTO `DEPARTMENT` VALUES (1,'Tico-Tico','Francisco SÃ¡ 3241/8 Friburgo RJ'),(2,'Joao de Barro','Getulio Vargas 45 Petropolis RJ'),(3,'Beija-Flor','13 de MarÃ§o 56/7Â° Teresopolis RJ'),(4,'SabiÃ¡','Afonso Pena 45/7 Resende RJ');
/*!40000 ALTER TABLE `DEPARTMENT` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DEPENDENT`
--

DROP TABLE IF EXISTS `DEPENDENT`;
CREATE TABLE `DEPENDENT` (
  `EMPLOYEE_SSN` int(10) unsigned NOT NULL,
  `Fname` varchar(45) NOT NULL,
  `Minit` varchar(3) default NULL,
  `Lname` varchar(20) NOT NULL,
  `Sex` varchar(3) NOT NULL,
  `BDate` date default NULL,
  `Relationship` varchar(20) NOT NULL,
  PRIMARY KEY  (`EMPLOYEE_SSN`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `DEPENDENT`
--

LOCK TABLES `DEPENDENT` WRITE;
/*!40000 ALTER TABLE `DEPENDENT` DISABLE KEYS */;
INSERT INTO `DEPENDENT` VALUES (159753,'Marcelo','B','Castro','M','1998-04-05','irmao'),(321654,'Raphael','T','Roque','M','1984-11-19','primo'),(789321,'Manuela','R','Lacerda','F','1995-04-30','irma'),(951357,'Lucas','S','Cabral','M','1964-09-25','pai'),(852741,'Alice','K','Borges','F','1994-12-01','tia');
/*!40000 ALTER TABLE `DEPENDENT` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `EMPLOYEE`
--

DROP TABLE IF EXISTS `EMPLOYEE`;
CREATE TABLE `EMPLOYEE` (
  `SSN` int(10) unsigned NOT NULL,
  `Supervisor` int(10) unsigned NOT NULL,
  `DEPARTMENT_Number` int(11) NOT NULL,
  `Bdate` date NOT NULL,
  `Fname` varchar(20) NOT NULL,
  `Minit` varchar(3) default NULL,
  `Lname` varchar(20) NOT NULL,
  `Sex` varchar(3) NOT NULL,
  `Street` varchar(20) default NULL,
  `Num` float default NULL,
  `Complement` varchar(10) default NULL,
  `City` varchar(20) default NULL,
  `State` varchar(20) default NULL,
  `ZipCode` int(10) unsigned default NULL,
  `Salary` float NOT NULL,
  PRIMARY KEY  (`SSN`),
  KEY `DEPARTMENT_Number` (`DEPARTMENT_Number`),
  KEY `Supervisor` (`Supervisor`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `EMPLOYEE`
--

LOCK TABLES `EMPLOYEE` WRITE;
/*!40000 ALTER TABLE `EMPLOYEE` DISABLE KEYS */;
INSERT INTO `EMPLOYEE` VALUES (123456,123456,1,'2000-01-01','Raquel','L','Costa','F','Itambe',232,'0','Contagem','Minas Gerais',32285110,1500),(654321,123456,2,'1980-02-02','Barbara','M','Souza','F','Parana',32,'5','Belo Horizonte','Minas Gerais',32285000,1800),(852369,852369,3,'1950-06-01','Francisco','F','Costa','M','Itambe',2,'0','Sete Lagoas','Minas Gerais',36285110,2000),(159753,123456,4,'2004-07-01','Rodrigo','O','Castro','M','Itapemirim',87,'3','Lagoa Santa','Minas Gerais',35285110,3000),(789654,789654,1,'2001-08-01','Tiago','-','Souza','M','Dom Pedro',587,'0','Ipatinga','Minas Gerais',34285110,4000),(741258,123456,2,'2004-11-01','Bruno','P','Borges','M','Salvador',784,'8','Ouro Branco','Minas Gerais',33285110,5000),(456321,789654,3,'1995-10-01','Pedro','-','Magalhaes','M','Cuba',22,'0','Campos','Rio de Janeiro',32285110,1200),(741852,123456,4,'1994-09-01','Lucas','R','Pereira','M','Ouvidor',124,'0','Araras','Sao Paulo',32285110,6500),(321654,852369,1,'1977-08-01','Natalia','V','Roque','F','Tamoios',27,'1','Petropolis','Rio de Janeiro',32285110,1500),(951357,123456,2,'1979-07-01','Luciana','-','Cabral','F','Tupis',92,'0','Cordisburgo','Minas Gerais',32285110,800),(753159,789654,3,'2004-06-01','Monica','E','Rosa','F','Goitacazes',832,'0','Esmeralda','Minas Gerais',37285110,900),(789321,123456,4,'2005-05-01','Juliana','D','Lacerda','F','Timbiras',702,'0','Fortaleza','Ceara',32285000,1800),(258369,852369,1,'1999-04-01','Diego','C','Marinho','M','Get. Vargas',332,'8','Manaus','Amazonas',42285110,4500),(852741,123456,2,'1984-03-01','Felipe','A','Lopes','M','CaraÃ§a',42,'7','Pimenta Bueno','Rondonia',22285200,2300),(159263,852369,1,'1965-02-01','Renata','B','Borges','F','Corcovado',86,'0','Nova Lima','Minas Gerais',22295110,5400);
/*!40000 ALTER TABLE `EMPLOYEE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PROJECT`
--

DROP TABLE IF EXISTS `PROJECT`;
CREATE TABLE `PROJECT` (
  `Number` int(10) unsigned NOT NULL auto_increment,
  `DEPARTMENT_Number` int(11) NOT NULL,
  `Location` int(10) unsigned default NULL,
  `Name` varchar(45) NOT NULL,
  PRIMARY KEY  (`Number`),
  KEY `DEPARTMENT_Number` (`DEPARTMENT_Number`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `PROJECT`
--

LOCK TABLES `PROJECT` WRITE;
/*!40000 ALTER TABLE `PROJECT` DISABLE KEYS */;
INSERT INTO `PROJECT` VALUES (1,3,1,'Cerrado'),(2,4,2,'Mata Atlantica');
/*!40000 ALTER TABLE `PROJECT` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Works_on`
--

DROP TABLE IF EXISTS `Works_on`;
CREATE TABLE `Works_on` (
  `EMPLOYEE_SSN` int(10) unsigned NOT NULL,
  `PROJECT_Number` int(10) unsigned NOT NULL,
  `Hrs` int(10) unsigned default NULL,
  PRIMARY KEY  (`EMPLOYEE_SSN`,`PROJECT_Number`),
  KEY `PROJECT_Number` (`PROJECT_Number`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Works_on`
--

LOCK TABLES `Works_on` WRITE;
/*!40000 ALTER TABLE `Works_on` DISABLE KEYS */;
INSERT INTO `Works_on` VALUES (123456,1,40),(654321,2,45),(852369,1,60),(159753,2,40),(789654,1,40),(741258,2,40),(456321,1,40),(741852,2,40),(321654,1,60),(951357,2,20),(753159,1,40),(789321,2,20),(258369,1,20),(852741,2,20);
/*!40000 ALTER TABLE `Works_on` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2008-08-21 19:46:08
