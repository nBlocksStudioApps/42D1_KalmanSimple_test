FOR /d /r . %%d IN (".git") DO @IF EXIST "%%d" rd /s /q "%%d"
