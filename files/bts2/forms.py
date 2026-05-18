import pyxel

class FormControl :

    def __init__(self, name : str, value) -> None :
        self._name = name
        self._value = value
        self._x = 0
        self._y = 0

    def setCoord(self, x : int, y : int) -> None :
        self._x = x
        self._y = y

    def getValue(self) :
        return self._value

    def getName(self) :
        return self._name
    
    def __str__(self) -> str:
        if type(self._value) is str :
            return "\"" + self._name + "\" : \"" + self._value + "\""
        else :    
            return "\"" + self._name + "\" : " + str(self._value)

class Alignable :

    ALIGN_LEFT    = -1
    ALIGN_CENTER  =  0
    ALIGN_RIGHT   =  1

    def __init__(self, align : int = ALIGN_LEFT) -> None :
        self._align = align

    def getAlign(self) -> int :
        return self._align

class Checkbox(FormControl) : 

    def __init__(self, name : str, label : str, checked : bool = False, color : int = 7) -> None:
        """
        Crée une checkbox
        
        :param name: Le nom de la checkbox (exporté)
        :type name: str
        :param label: Le libellé qui suit la checkbox
        :type label: str
        :param checked: L'état de la checkbox (exporté)
        :type checked: bool
        :param color: Couleur de la checkbox
        :type color: int
        """
        super().__init__(name, checked)
        self.__color = color
        self.__checked = checked
        self.__label = label
        self.__w = 10 + len(label) * 4

    def getHeight(self) -> int :
        return 7

    def isChecked(self) -> bool :
        return self.__checked
    
    def setChecked(self, checked) -> None :
        self.__checked = checked
    
    def update(self) -> None :
        # Gestion du clic
        if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) and self._x <= pyxel.mouse_x < self._x + self.__w and self._y <= pyxel.mouse_y < self._y + 7 :
            self.__checked = not self.__checked
            self._value = self.__checked

    def draw(self) -> None :
        # Affichage de la case
        pyxel.rectb(self._x, self._y, 7, 7, self.__color)
        
        # Croix
        if self.__checked :
            pyxel.line(self._x + 2, self._y + 2, self._x + 4, self._y + 4, self.__color)
            pyxel.line(self._x + 4, self._y + 2, self._x + 2, self._y + 4, self.__color)
        
        # Affichage du texte
        pyxel.text(self._x + 10, self._y + 1, self.__label, self.__color)

class RadioOption :

    def __init__(self, label : str, value, checked : bool = False, color : int = 7) -> None:
        self.__x = 0
        self.__y = 0
        self.__color = color
        self.__checked = checked
        self.__label = label
        self.__value = value
        self.__w = 10 + len(label) * 4

    def setCoord(self, x : int, y : int) -> None :
        self.__x = x
        self.__y = y

    def isChecked(self) -> bool :
        return self.__checked
    
    def setChecked(self, checked) -> None :
        self.__checked = checked

    def getValue(self) :
        return self.__value
    
    def update(self) -> None :
        # Gestion du clic
        if not self.__checked and pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) and self.__x <= pyxel.mouse_x < self.__x + self.__w and self.__y <= pyxel.mouse_y < self.__y + 7 :
            self.__checked = not self.__checked

    def draw(self) -> None :
        # Affichage de la case
        pyxel.circb(self.__x + 3, self.__y + 3, 3, self.__color)
        
        # Croix
        if self.__checked :
            pyxel.circ(self.__x + 3, self.__y + 3, 1, self.__color)
        
        # Affichage du texte
        pyxel.text(self.__x + 10, self.__y + 1, self.__label, self.__color)

class Radio(FormControl) : 

    def __init__(self, name : str, options : list, selected : int = 0, color : int = 7) -> None:
        """
        Crée un groupe de bouton radio
        
        :param name: Le nom du groupe de boutons radio (exporté)
        :type name: str
        :param options: La liste des boutons radio, chaque bouton doit être décrit par un dictionnaire { "label" : "le texte qui suit le bouton", "value" : la valeur exportée si le bouton est sélectionné }
        :type options: list
        :param selected: Le numéro du bouton radio sélectionné (indexé à 1)
        :type selected: int
        :param color: La couleur  du groupe de boutons radio
        :type color: int
        """
        super().__init__(name, options[selected]["value"])
        self.__selected = selected - 1
        self.__options = []
        for i in range(len(options)) :
            self.__options.append(RadioOption(options[i]["label"], options[i]["value"], i == selected - 1, color))

    def setCoord(self, x : int, y : int) -> None :
        self._x = x
        self._y = y
        for i in range(len(self.__options)) :
            self.__options[i].setCoord(self._x, self._y + i * 9)
            
    def getHeight(self) -> int :
        return 9 * len(self.__options) - 2

    def update(self) :
        # Mise à jour des options
        selected = self.__selected
        for i in range(len(self.__options)) :
            previousState = self.__options[i].isChecked()
            self.__options[i].update()
            if self.__options[i].isChecked() != previousState :
                selected = i

        # Gestion de la sélection unique
        if selected != self.__selected :
            for i in range(len(self.__options)) :
                if i != selected :
                    self.__options[i].setChecked(False)
        self.__selected = selected
        self._value = self.__options[self.__selected].getValue()
        
    def draw(self) :
        for i in range(len(self.__options)) :
            self.__options[i].draw()

class Textbox(FormControl) :

    def __init__(self, name : str, value : str = "", maxLength : int = 20, password : bool = False, color : int = 7) -> None:
        """
        Crée une textbox
        
        :param name: Le nom de la textbox (exporté)
        :type name: str
        :param value: La valeur par défaut de la textbox (exporté)
        :type value: str
        :param maxLength: Nombre de caractères maximum
        :type maxLength: int
        :param password: Masquage des caractères
        :type password: bool
        :param color: La couleur de la textbox
        :type color: int
        """
        super().__init__(name, value)
        self.__w = maxLength * 4 + 4
        self.__maxLength = maxLength
        self.__password = password
        self.__color = color
        self.__hasFocus = False
        self._value = value

    def getHeight(self) -> int :
        return 9

    def update(self) -> None :
        # Focus
        if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) :
            self.__hasFocus = self._x <= pyxel.mouse_x < self._x + self.__w and self._y <= pyxel.mouse_y < self._y + 9

        # Saisie (TO DO : gestion du clavier AZERTY complet)
        if self.__hasFocus and len(self._value) < self.__maxLength :
            for i in range(32, 127) :
                if pyxel.btnp(i) :
                    if 97 <= i <= 122 :
                        self._value += chr(i - (32 if pyxel.btn(pyxel.KEY_SHIFT) else 0))
                    else :
                        self._value += chr(i)

        # Correction
        if self.__hasFocus and pyxel.btnp(pyxel.KEY_BACKSPACE) and len(self._value) > 0 :
            self._value = self._value[:-1]
    
    def draw(self) -> None :
        # Boite
        pyxel.rectb(self._x, self._y, self.__w, 9, self.__color)
        if not self.__password :
            pyxel.text(self._x + 2, self._y + 2, self._value, self.__color)
        else :
            pyxel.text(self._x + 2, self._y + 2, "".rjust(len(self._value), "*"), self.__color)
        
        # Curseur
        if self.__hasFocus :
            if (pyxel.frame_count % 40 > 20) :
                x = self._x + len(self._value) * 4 + 2
                pyxel.line(x, self._y + 2, x, self._y + 6, 7) 

class Button (Alignable) :

    def __init__(self, label : str, onClick : callable, enabled : bool = True, color : int = 7, align : int = Alignable.ALIGN_RIGHT) :
        """
        Crée un bouton
        
        :param label: Le libellé du bouton
        :type label: str
        :param onClick: La fonction appelée quand on clique sur le bouton
        :type onClick: callable
        :param enabled: Activation du bouton
        :type enabled: bool
        :param color: La couleuur du bouton
        :type color: int
        :param align: L'alignement du bouton par rapport à l'écran
        :type align: int
        """
        Alignable.__init__(self, align)
        self.__label = label
        self.__x = 0
        self.__y = 0
        self.__w = len(label) * 4 + 7
        self.__h = 9
        self.__onClick = onClick
        self.__clicked = False
        self.__enabled = enabled
        self.__color = color

    def setCoord(self, x : int, y : int) -> None :
        self.__x = x
        if self._align == Alignable.ALIGN_CENTER :
            self.__x = pyxel.width // 2 - self.__w // 2
        elif self._align == Alignable.ALIGN_RIGHT :
            self.__x = pyxel.width - x - self.__w
        self.__y = y + 2

    def getHeight(self) -> int :
        return 12

    def setEnabled(self, enabled : bool) :
        self.__enabled = enabled
        
    def isEnabled(self) :
        return self.__enabled

    def update(self) :
        if self.__enabled :
            # Bouton pressé
            if self.__x < pyxel.mouse_x < self.__x + self.__w and self.__y < pyxel.mouse_y < self.__y + self.__h and pyxel.btn(pyxel.MOUSE_BUTTON_LEFT) :
                self.__clicked = True
            # Bouton relâché
            elif self.__x < pyxel.mouse_x < self.__x + self.__w and self.__y < pyxel.mouse_y < self.__y + self.__h and pyxel.btnr(pyxel.MOUSE_BUTTON_LEFT) :
                self.__clicked = False
                self.__onClick()
            else :
                self.__clicked = False

    def draw(self) :
        # Couleur
        color = self.__color if self.__enabled else 13
        
        # Ombre
        pyxel.rect(self.__x + 1, self.__y + 1, self.__w, self.__h, 13)

        # Bouton
        if self.__clicked :
            pyxel.rect(self.__x + 2, self.__y + 2, self.__w - 2, self.__h - 2, 0)
            pyxel.rectb(self.__x + 1, self.__y + 1, self.__w, self.__h, color)
            pyxel.text(self.__x + 5, self.__y + 3, self.__label, color)
        else :
            pyxel.rect(self.__x + 1, self.__y + 1, self.__w - 2, self.__h - 2, 0)
            pyxel.rectb(self.__x, self.__y, self.__w, self.__h, color)
            pyxel.text(self.__x + 4, self.__y + 2, self.__label, color)

class Label (Alignable) :

    def __init__(self, text : str, color = 7, align : int = Alignable.ALIGN_LEFT) :
        """
        Crée un Label
        
        :param text: Le texte du libellé
        :type text: str
        :param color: La couleur du libellé
        :param align: L'alignement du libellé par rapport à l'écran
        :type align: int
        """
        Alignable.__init__(self, align)
        self.__text = text
        self.__color = color
        self.__x = 0
        self.__y = 0

    def setCoord(self, x : int, y : int) -> None :
        self.__x = x
        if self._align == Alignable.ALIGN_CENTER :
            self.__x = pyxel.width // 2 - len(self.__text) * 4 // 2
        elif self._align == Alignable.ALIGN_RIGHT :
            self.__x = pyxel.width - x - len(self.__text) * 4
        self.__y = y

    def getHeight(self) -> int :
        return 7
    
    def setText(self, text : str) -> None :
        self.__text = text
    
    def update(self) -> None :
        pass

    def draw(self) -> None :
        pyxel.text(self.__x, self.__y + 2, self.__text, self.__color)

class Form :

    def __init__(self, items : list, margin : list | int = 0, padding : list | int = 2, border : bool = False, color : int = 7) :
        """
        Crée un formulaire
        
        :param items: La liste des items (Textbox, Checkbox, Radio, Button, Label) du formulaire dans l'ordre souhaité d'affichage
        :type items: list
        :param margin: La marge extérieure du formulaire
        :type margin: list | int
        :param padding: La marge intérieure du formulaire
        :type padding: list | int
        :param border: Ajout d'une bordure au formulaire
        :type border: bool
        """
        self.__items = items

        # Gestion du margin
        if type(margin) == int :
            self.__x = margin
            self.__y = margin
            self.__w = pyxel.width - 2 * margin
            self.__h = pyxel.height - 2 * margin
            itemsHeight = margin
        else :
            self.__x = margin[3]
            self.__y = margin[0]
            self.__w = pyxel.width - (margin[1] + margin[3])
            self.__h = pyxel.height - (margin[0] + margin[2])
            itemsHeight = margin[0]

        # Gestion du padding
        if type(padding) == int :
            itemsHeight += padding
            paddingLeft = padding
            paddingRight = padding
        else :
            itemsHeight += padding[0]
            paddingLeft = padding[3]
            paddingRight = padding[1]

        # Gestion de la bordure
        self.__border = border
        if border :
            itemsHeight += 1
            paddingLeft += 1

        self.__color = color

        # Placement des items
        for i in range(len(self.__items)) :
            if isinstance(self.__items[i], Alignable) and self.__items[i].getAlign() == Alignable.ALIGN_RIGHT :
                self.__items[i].setCoord(self.__x + paddingRight, itemsHeight)
            else :
                self.__items[i].setCoord(self.__x + paddingLeft, itemsHeight)
            itemsHeight += self.__items[i].getHeight() + 2

    def __str__(self) -> str:
        return self.toJson()
    
    def __repr__(self) -> str:
        return self.toJson()

    def toJson(self) -> str :
        result = []
        for i in range(len(self.__items)) :
            if type(self.__items[i]) in [Textbox, Checkbox, Radio] :
                result.append(str(self.__items[i]))
        return "{ " + ", ".join(result) + " }"
    
    def toDict(self) -> dict :
        result = {}
        for i in range(len(self.__items)) :
            if type(self.__items[i]) in [Textbox, Checkbox, Radio] :
                result[self.__items[i].getName()] = self.__items[i].getValue()
        return result
    
    def items(self, i : int) :
        return self.__items[i]
    
    def update(self) -> None :
        for i in range(len(self.__items)) :
            self.__items[i].update()

    def draw(self) -> None :
        pyxel.rect(self.__x, self.__y, self.__w, self.__h, 0)

        if self.__border :
            pyxel.rectb(self.__x, self.__y, self.__w, self.__h, self.__color)

        for i in range(len(self.__items)) :
            self.__items[i].draw()