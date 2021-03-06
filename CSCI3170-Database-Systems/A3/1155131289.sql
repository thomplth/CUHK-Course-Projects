/*
    Student ID: ***
    Name: ***
*/
/* Query 1 */
Spool result1.lst
SELECT L1.LID, L1.LEAGUE_NAME, R1.REGION_NAME, L1.YEAR
FROM LEAGUES L1, REGIONS R1
WHERE (L1.SEASON='Spring' OR L1.SEASON='Summer') AND L1.RID=R1.RID
ORDER BY L1.LID ASC;
Spool off
/* Query 2 */
CREATE OR REPLACE VIEW TEMP AS
SELECT CHAMPION_TID, WC
FROM (
  SELECT CHAMPION_TID, COUNT(*) AS WC
  FROM LEAGUES
  WHERE SEASON='Autumn'
  GROUP BY CHAMPION_TID)
WHERE WC > 1;
Spool result2.lst
SELECT T2.TID, T2.TEAM_NAME, T2.AVERAGE_AGE
FROM TEAMS T2
INNER JOIN TEMP TP2
ON T2.TID=TP2.CHAMPION_TID
ORDER BY T2.TID ASC;
Spool off
DROP VIEW TEMP;
/* Query 3 */
CREATE OR REPLACE VIEW TEMP AS
SELECT L3.CHAMPION_TID, L3.SEASON, COUNT(*) AS W_NUM 
FROM LEAGUES L3
GROUP BY L3.CHAMPION_TID, L3.SEASON
ORDER BY L3.CHAMPION_TID, L3.SEASON;
Spool result3.lst
SELECT TP3.CHAMPION_TID, T3.TEAM_NAME, T3.AVERAGE_AGE, TP3.SEASON, TP3.W_NUM
FROM TEMP TP3, TEAMS T3
WHERE W_NUM >= ALL (
  SELECT W_NUM
  FROM (
    SELECT L3.CHAMPION_TID, L3.SEASON, COUNT(*) AS W_NUM 
    FROM LEAGUES L3
    WHERE TP3.SEASON = L3.SEASON
    GROUP BY L3.CHAMPION_TID, L3.SEASON
    ORDER BY L3.CHAMPION_TID, L3.SEASON))
AND TP3.CHAMPION_TID = T3.TID
ORDER BY T3.TID, TP3.SEASON ASC;
Spool off
DROP VIEW TEMP;
/* Query 4 */
Spool result4.lst
SELECT SID, SPONSOR_NAME, L_NUM
FROM (
  SELECT SUPPORT.SID, SPONSORS.SPONSOR_NAME, COUNT(*) AS L_NUM
  FROM SUPPORT, SPONSORS
  WHERE SUPPORT.SID=SPONSORS.SID
  GROUP BY SUPPORT.SID, SPONSORS.SPONSOR_NAME)
WHERE ROWNUM < 6
ORDER BY SID ASC;
Spool off
/* Query 5 */
Spool result5.lst
SELECT DISTINCT L5.LID, L5.LEAGUE_NAME
FROM LEAGUES L5
INNER JOIN (
  SELECT P5.LID
  FROM SPONSORS S5, SUPPORT P5
  WHERE S5.SID=P5.SID AND S5.MARKET_VALUE>50) TP1 
ON L5.LID=TP1.LID
INNER JOIN (
  SELECT TID
  FROM TEAMS
  WHERE AVERAGE_AGE<30) TP2
ON L5.CHAMPION_TID=TP2.TID
WHERE L5.SEASON='Autumn' OR L5.SEASON='Winter'
ORDER BY L5.LID DESC;
Spool off
/* Query 6 */
CREATE OR REPLACE VIEW TSPON AS
SELECT S6.SID, L6.RID, SUM(SPONSORSHIP) AS RSPON
FROM SPONSORS S6, SUPPORT P6, LEAGUES L6
WHERE S6.SID=P6.SID AND P6.LID=L6.LID
GROUP BY S6.SID, L6.RID
ORDER BY S6.SID;
CREATE OR REPLACE VIEW THOT AS
SELECT S6.SID, R6.RID, T.RSPON/(SQRT(S6.MARKET_VALUE)*LOG(2, SQRT(R6.FOOTBALL_RANKING)+1)) AS HOT
FROM SPONSORS S6, REGIONS R6, TSPON T
WHERE S6.SID=T.SID AND R6.RID=T.RID;
CREATE OR REPLACE VIEW TEMP AS
SELECT S6.SID, SUM(HOT) AS HOT
FROM SPONSORS S6, REGIONS R6, THOT TH
WHERE S6.SID=TH.SID AND R6.RID=TH.RID AND S6.MARKET_VALUE>40 AND R6.FOOTBALL_RANKING<10
GROUP BY S6.SID;
Spool result6.lst
SELECT SID, HOT
FROM TEMP
WHERE HOT IN (
  SELECT MAX(HOT)
  FROM TEMP)
ORDER BY SID DESC;
Spool off
DROP VIEW TSPON;
DROP VIEW THOT;
DROP VIEW TEMP;
/* Query 7 */
CREATE OR REPLACE VIEW TSPON AS
SELECT S6.SID, L6.RID, SUM(SPONSORSHIP) AS RSPON
FROM SPONSORS S6, SUPPORT P6, LEAGUES L6
WHERE S6.SID=P6.SID AND P6.LID=L6.LID
GROUP BY S6.SID, L6.RID
ORDER BY S6.SID;
CREATE OR REPLACE VIEW THOT AS
SELECT S6.SID, R6.RID, T.RSPON/(SQRT(S6.MARKET_VALUE)*LOG(2, SQRT(R6.FOOTBALL_RANKING)+1)) AS HOT
FROM SPONSORS S6, REGIONS R6, TSPON T
WHERE S6.SID=T.SID AND R6.RID=T.RID;
Spool result7.lst
SELECT TEMP.RID, COL4.HOT_4, COL5.HOT_5, COL6.HOT_6, COL7.HOT_7, MAX(GREATEST(NVL(COL4.HOT_4,0),NVL(COL5.HOT_5,0),NVL(COL6.HOT_6,0),NVL(COL7.HOT_7,0))) AS HOT_HIGH
FROM (
  SELECT RID
  FROM REGIONS) TEMP
LEFT OUTER JOIN (
  SELECT R7.RID, TH4.HOT AS HOT_4
  FROM THOT TH4, REGIONS R7
  WHERE TH4.SID = 4 AND R7.RID = TH4.RID) COL4
ON COL4.RID = TEMP.RID
LEFT OUTER JOIN (
  SELECT R7.RID, TH5.HOT AS HOT_5
  FROM THOT TH5, REGIONS R7
  WHERE TH5.SID = 5 AND R7.RID = TH5.RID) COL5
ON COL5.RID = TEMP.RID
LEFT OUTER JOIN (
  SELECT R7.RID, TH6.HOT AS HOT_6
  FROM THOT TH6, REGIONS R7
  WHERE TH6.SID = 6 AND R7.RID = TH6.RID) COL6
ON COL6.RID = TEMP.RID
LEFT OUTER JOIN (
  SELECT R7.RID, TH7.HOT AS HOT_7
  FROM THOT TH7, REGIONS R7
  WHERE TH7.SID = 7 AND R7.RID = TH7.RID) COL7
ON COL7.RID = TEMP.RID
GROUP BY TEMP.RID, HOT_4, HOT_5, HOT_6, HOT_7
ORDER BY TEMP.RID DESC;
Spool off
DROP VIEW TSPON;
DROP VIEW THOT;
/* Query 8 */
Spool result8.lst
SELECT DISTINCT S8.SID, S8.SPONSOR_NAME
FROM SPONSORS S8, SUPPORT P8
WHERE S8.SID=P8.SID AND P8.LID IN (
  SELECT LID
  FROM LEAGUES
  WHERE CHAMPION_TID IN (
    SELECT CHAMPION_TID
    FROM LEAGUES
    GROUP BY CHAMPION_TID
    HAVING COUNT(*) = (
      SELECT MAX(W_NUM)
      FROM (
        SELECT CHAMPION_TID, COUNT(*) AS W_NUM
        FROM LEAGUES
        GROUP BY CHAMPION_TID))))
ORDER BY S8.SID ASC;
Spool off
