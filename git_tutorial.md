
# 🌊 Workflow Git - Progetto_EOS

Segui questa procedura passo-passo ogni volta che devi apportare una modifica al progetto.

## 1. Scaricare la Repository (Clone)
*Da fare solo la prima volta per scaricare il progetto sul tuo computer.*

```bash
git clone https://github.com/danieledisint/Progetto_EOS
cd Progetto_EOS
````

-----

## 2\. Creare il tuo Branch

*Non lavorare mai direttamente su `main`. Crea un ramo dedicato per la tua modifica.*

```bash
# Crea un nuovo branch e spostati su di esso
git checkout -b nome-branch
```

> *Consiglio: usa il tuo nome in modo da avere il tuo branch personale

-----

## 3\. Preparare le modifiche (Add)

*Dopo aver modificato o creato i file, preparali per il salvataggio.*

```bash
# Aggiunge tutti i file modificati
git add .
```

-----

## 4\. Salvare le modifiche (Commit)

*Crea un "punto di salvataggio" nella storia del progetto.*

```bash
# Scrivi un messaggio chiaro tra virgolette
git commit -m "Descrizione di cosa hai fatto"
```

-----

## 5\. Inviare online (Push)

*Carica il tuo branch sul server remoto (GitHub/GitLab).*

```bash
# La prima volta che invii un nuovo branch:
git push -u origin nome-branch
```

-----

### Riepilogo veloce per chi ha fretta:

1.  `git checkout -b nuova-feature` (Crea ramo)
2.  `git add .` (Prepara file)
3.  `git commit -m "messaggio"` (Salva)
4.  `git push -u origin nuova-feature` (Invia)

<!-- end list -->
