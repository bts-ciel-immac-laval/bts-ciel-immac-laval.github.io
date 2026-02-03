# Projet Charlie

![charlie](../images/illustration/charlie.jpg)

Lorsqu'un pirate s'introduit dans un serveur hébergeant un (ou des) site(s) web, son objectif n'est pas de "détruire" le serveur, mais d'y ajouter des scripts (ou de modifier des scripts existants) pour nuire à l'activité du site web (en diffusant de la propagande par exemple...).

![pirate](../images/illustration/pirate.jpg){ align=right }

En supplément de mesures anti-intusion, on vous demande de développer un programme capable de comparer l'état d'un dossier entre deux exécutions.

Le programme doit fournir une liste des fichiers ajoutés, modifiés ou supprimés depuis la précédente exécution du programme.

Pour éviter les faux positifs, on créera une liste d'exclusion.

Optionnellement, le programme gèrera son historique de rapport en le purgeant régulièrement (durée de rétention paramétrable).

### Analyse / Conception

Les techniques que nous devons maîtriser :

- [ ] Parcourir un dossier

    - [x] Lister les fichiers contenus dans un dossier

    Utilisation de dirent.h

    - [ ] Naviguer en profondeur dans l'arborescence

- [ ] Détecter la modification d'un fichier

    - [ ] Récupérer la date de dernière modification d'un fichier
    
    - [ ] Récupérer la taille d'un fichier
    
    - [ ] Calculer un checksum d'un fichier
    
- [x] Générer un tableau avec les informations (données structurées)
    
- [ ] Sauvegarder le tableau entre deux exécutions

    - [ ] Sauvegarder un fichier binaire

    - [ ] Trouver une convention de nommage (si plusieurs dossiers surveillés)

    - [ ] Charger le tableau à partir du fichier

- [x] Comparer deux tableaux

    - [x] Détecter un ajout

    - [x] Détecter une suppression

    - [x] Détecter une modification

- [x] Générer le rapport

    - [x] Ecrire un fichier au format CSV

- [ ] Gérer la purge des fichiers

    - [ ] Supprimer un fichier

- [ ] Gérer une liste d'exclusion

### Ressources

[:material-file-download: Télécharger dirent.h](../files/bts1/dirent.h){ .md-button .md-button--primary }