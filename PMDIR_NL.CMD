/* PMDIR.CMD */

CALL RxFuncAdd 'SysSetObjectData','RexxUtil','SysSetObjectData'

SAY
SAY 'PMDIR [[B]oomstructuur | [D]etails | [P]ictogrammen | [I]nstellingen]'
SAY 'Map->' Directory()

ARG 1 type +1 

SELECT
   WHEN type="P" THEN view="ICON"
   WHEN type="D" THEN view="DETAILS"
   WHEN type="B" THEN view="TREE"
   WHEN type="I" THEN view="SETTINGS"
   OTHERWISE view="DEFAULT"
END

setting="OPEN="||view||";"

CALL SysSetObjectData Directory(),setting /* open object */
CALL SysSetObjectData Directory(),setting /* move object to foreground */

EXIT

