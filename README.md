# csv-json-converter

Tato aplikace umožňuje konverzi dat z formátu CSV (Comma-Separated Values) do formátu JSON (JavaScript Object Notation) a zpět. Zde naleznete návod k použití a příklady CSV a JSON souborů, které lze použít.

## Použití

1.) Spuštění aplikace:

```shell
./csv_json_converter <vstupní_soubor> <výstupní_soubor> <režim>
```
    
- `<vstupní_soubor>`: Cesta k vstupnímu souboru ve formátu CSV nebo JSON.
- `<výstupní_soubor>`: Cesta k výstupnímu souboru, kam bude uložen výsledek konverze ve formátu JSON nebo CSV.
- `<režim>`: Režim konverze, který může být csv-to-json (z CSV do JSON) nebo json-to-csv (z JSON do CSV).

2.) Příklad použití:

```shell
./csv_json_converter vstup.csv vystup.json csv-to-json
```

## Příklady CSV a JSON
### Příklad CSV souboru (vstup.csv):

```csv
"Jméno";"Příjmení";"Věk"
"Jan";"Novák";30
"Eva";"Svobodová";25
"Petr";"Dvořák";35
```

### Příklad JSON souboru (vstup.json):

```json

[
{
"Jméno": "Jan",
"Příjmení": "Novák",
"Věk": "30"
},
{
"Jméno": "Eva",
"Příjmení": "Svobodová",
"Věk": "25"
},
{
"Jméno": "Petr",
"Příjmení": "Dvořák",
"Věk": "35"
}
]
```

## Poznámky
- Aplikace podporuje oddělovače v CSV souborech: ;, , a \t (tabulátor).
- Při konverzi z CSV do JSON je třeba zajistit, že první řádek CSV obsahuje hlavičky.
- Při konverzi z JSON do CSV je očekáván formát JSON pole obsahujícího objekty.

## Licence

Tato aplikace je poskytována bez záruky a je k dispozici pod licencí MIT License. Používání této aplikace je na vlastní riziko.

&copy; Zdeněk Carbol