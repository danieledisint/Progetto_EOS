# 📘 Guida Git per Progetto_EOS

Questa è la guida rapida per contribuire al repository **Progetto_EOS**.
Segui queste istruzioni per mantenere la cronologia pulita e lavorare senza conflitti.

-----

## 🔄 Il Flusso di Lavoro (Workflow)

Ogni volta che devi apportare modifiche al **Progetto\_EOS**, segui rigorosamente questo ordine:

### 1\. Sincronizza (PRIMA di lavorare)

Scarica sempre le ultime modifiche dei colleghi per evitare conflitti.

```bash
git pull origin main
```

### 2\. Lavora e Controlla

Fai le tue modifiche ai file. Poi controlla cosa hai toccato:

```bash
git status
```

### 3\. Prepara le modifiche (Stage)

Aggiungi i file modificati all'area di preparazione.

```bash
git add .
```

> *Nota: Se vedi warning su "CRLF replaced by LF", ignorali. È Git che gestisce la compatibilità Windows/Linux.*

### 4\. Salva (Commit)

Crea il salvataggio locale. **Il messaggio deve essere chiaro.**

```bash
git commit -m "Descrizione breve di cosa hai fatto (es. fix driver sensore)"
```

### 5\. Invia (Push)

Invia il tuo lavoro sul server (GitHub/GitLab).

```bash
git push origin main
```

-----

## 🌿 Lavorare su nuove funzionalità (Branch)

Se devi fare una modifica grossa o sperimentale, NON lavorare direttamente su `main`.

1.  **Crea un nuovo ramo:**
    ```bash
    git checkout -b nome-tua-funzionalita
    ```
2.  **Lavora, fai Add e Commit come sopra.**
3.  **Invia il nuovo ramo online:**
    ```bash
    git push -u origin nome-tua-funzionalita
    ```

-----

## 🆘 Comandi di Emergenza

  * **Ho sbagliato tutto, voglio tornare all'ultimo commit pulito:**
    `git checkout .` (Attenzione: cancella le modifiche non salvate\!)
  * **Voglio vedere la storia dei salvataggi:**
    `git log` (Premi `q` per uscire)

<!-- end list -->

```
```
