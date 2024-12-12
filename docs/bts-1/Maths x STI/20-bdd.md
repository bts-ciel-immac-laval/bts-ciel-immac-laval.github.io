# 02 - Bases de données

## Support

<object class="fullScreenAble" data="../../../pdf/cours/bts1/bts1_bdd_document.pdf" type="application/pdf"></object>

## Fichiers

[bts1_bdd_fichiers.zip](https://immaclaval-my.sharepoint.com/:u:/g/personal/mdomer_immac_fr/EQ-SF87oMCZJm7Wk6GYcw0cBQN8PfNyG1iY_nimPvQlnHw?e=9Qrpsb)

Mot de passe : cybersécurité-informatique-réseaux

## Repartir du bon pied

Dans DBeaver :

1.  Supprimer la base de données à remplacer en cliquant-droit sur la base de données **factures** puis en choisissant l'action **Supprimer**.

2.  Créer une nouvelle base de données **factures** en répétant les étapes de la section 3.3 du support.

    ![import](../../images/cours/bts-1/maths-sti-2/Capture%20d'écran%202024-12-12%20130852.png)

3.  Importer la table **produit** en en cliquant-droit sur la base de données **factures** puis en choisissant l'action **Outils > Restore database**.

    ![import](../../images/cours/bts-1/maths-sti-2/Capture%20d'écran%202024-12-12%20131524.png)

4.  Dans la fenêtre **Database Import**, charger le fichier [dump-factures-produits.sql](../../files/bts1/dump-factures-produits.sql) dans le champ **Input File**

5.  Cliquer sur **Démarrage**.

6.  Une fois l'import terminé, fermer la fenêtre d'import et reprendre à partir de la section 3.7 du support.