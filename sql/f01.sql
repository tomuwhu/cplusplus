SELECT  ev év,
        versenyszam.nev versenyszám

FROM    bajnok, egyesulet, jatekos, versenyszam

WHERE   bajnok.jatekos_id = jatekos.id and 
        bajnok.egyesulet_id = egyesulet.id and 
        bajnok.vsz_id = versenyszam.id and
        jatekos.nev = 'Harczi Zsolt'

ORDER BY bajnok.ev ASC