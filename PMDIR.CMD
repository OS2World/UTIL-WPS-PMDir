/* PMDIR.CMD */

CALL RxFuncAdd 'SysSetObjectData','RexxUtil','SysSetObjectData'

SAY
SAY 'PMDIR [[D]etails | [I]con | [T]ree | [S]ettings]'
SAY 'Folder->' Directory()

ARG 1 type +1 

SELECT
   WHEN type="D" THEN view="DETAILS"
   WHEN type="I" THEN view="ICON"
   WHEN type="T" THEN view="TREE"
   WHEN type="S" THEN view="SETTINGS"
   OTHERWISE view="DEFAULT"
END

setting="OPEN="||view||";"

CALL SysSetObjectData Directory(),setting /* open object */
CALL SysSetObjectData Directory(),setting /* move object to foreground */

EXIT
