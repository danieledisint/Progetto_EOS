
````markdown
# 🌊 Workflow Git - Progetto_EOS

Segui questa procedura passo-passo ogni volta che devi apportare una modifica al progetto.

## 1. Scaricare la Repository (Clone)
*Da fare solo la prima volta per scaricare il progetto sul tuo computer.*

```bash
git clone [https://github.com/danieledisint/Progetto_EOS](https://github.com/danieledisint/Progetto_EOS)
cd Progetto_EOS
````

-----

## 2\. Aggiornare il progetto (Pull)

**IMPORTANTE:** *Prima di iniziare a lavorare, assicurati di avere l'ultima versione del codice.*

```bash
# Torna sul ramo principale e scarica gli aggiornamenti
git checkout main
git pull origin main
```

-----

## 3\. Creare il tuo Branch

*Non lavorare mai direttamente su `main`. Crea un ramo dedicato per la tua modifica.*

```bash
# Crea un nuovo branch e spostati su di esso
git checkout -b nome-branch
```

> *Consiglio: usa il tuo nome in modo da avere il tuo branch personale.*

-----

## 4\. Preparare le modifiche (Add)

*Dopo aver modificato o creato i file, preparali per il salvataggio.*

```bash
# Aggiunge tutti i file modificati
git add .
```

-----

## 5\. Salvare le modifiche (Commit)

*Crea un "punto di salvataggio" nella storia del progetto.*

```bash
# Scrivi un messaggio chiaro tra virgolette
git commit -m "Descrizione di cosa hai fatto"
```

-----

## 6\. Inviare online (Push)

*Carica il tuo branch sul server remoto (GitHub/GitLab).*

```bash
# La prima volta che invii un nuovo branch:
git push -u origin nome-branch
```

-----

### Riepilogo veloce per chi ha fretta:

1.  `git pull origin main` (Aggiorna)
2.  `git checkout -b nome-branch` (Crea ramo)
3.  `git add .` (Prepara file)
4.  `git commit -m "messaggio"` (Salva)
5.  `git push -u origin nome-branch` (Invia)

<!-- end list -->

```
```
