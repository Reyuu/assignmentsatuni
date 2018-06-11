#python3.6
import random
import string

class Sprzet:
    def __init__(self, id, typ=None):
        self.type = typ
        self.types = ["rower", "hulajnoga", "rolki", None]
        self.id = id

    def check_if_correct_type(self, typ):
        if typ in self.types:
            return typ
        return None

class Osoba:
    def __init__ (self, id, nazwisko="Smith", wiek=18):
        self.nazwisko = nazwisko
        self.wiek = wiek
        self.id = id

class Wypozyczenie:
    def __init__(self, id_osoba, id_sprzet):
        self.id_osoba = id_osoba
        self.id_sprzet = id_sprzet

# brak funkcji udostepniajacych wartosci i do przypisywania
# bo bez sensu pisanie
# bo brak private keyword, wiec wszystko publiczne
# po prostu trzeba byc odpowiedzialnym za to co sie pisze xd

def generate_surname():
    s = ""
    length = random.randint(5, 9)
    for i in range(length):
        s += random.choice(string.ascii_lowercase)
    return s.capitalize()

if __name__ == "__main__":
    sprzeciory_dict = {}
    osobory_dict = {}
    wypozyczeniory = []
    for i in range(0, 100):
        sprzeciory_dict.update({i: Sprzet(i, random.choice(["rower", "hulajnoga", "rolki"]))})
        osobory_dict.update({i: Osoba(i, generate_surname(), random.randint(16, 99))})
        wypozyczeniory.append(Wypozyczenie(random.randint(0, 99), random.randint(0, 99)))
    option = 0
    running = True
    run_along = False
    while running:
        run_along = False
        print("1. Zapis danych do pliku")
        print("2. Odczyt danych z pliku")
        print("3. Lista osob, ponizej 25lat z wypozyczona hulajnoga")
        print("4. Liczba wypozyczonych rowerow")
        print("5. Wyjscie")
        try:
            option = int(input(">>> "))
        except ValueError:
            option = -1
        if option == 1:
            with open("dane.txt", "w") as f:
                #ima special snowflake, don care for csv
                for i in sprzeciory_dict.keys():
                    f.write("%s:%s\n" % (i, sprzeciory_dict[i].type))
                f.write("######\n")
                for i in osobory_dict.keys():
                    f.write("%s:%s:%s\n" % (i, osobory_dict[i].nazwisko, osobory_dict[i].wiek))
                f.write("######\n")
                for i in wypozyczeniory:
                    f.write("%s:%s\n" % (i.id_osoba, i.id_sprzet))
            print("Zapisano")
            run_along = True
            pass
        if option == 2:
            with open("dane.txt", "r") as f:
                all = f.read()
                all = all.split("######")
                #0 - sprzet, 1 - osoby, 2 - wypozyczenia
                sprzet = all[0].split("\n")
                osoby = all[1].split("\n")
                wypozczenia = all[2].split("\n")
                sprzeciory_dict.clear()
                osobory_dict.clear()
                wypozyczeniory.clear()
                #id, type
                for i in sprzet:
                    i = i.split(":")
                    #zostaja puste, jako ze uzywamy int,to jezeli nie bedzie prawidlowego str do int, wywali ValueErr
                    try:
                        sprzeciory_dict.update({int(i[0]): Sprzet(int(i[0]), i[1])})
                    except ValueError:
                        pass
                #id, nazwisko, wiek
                for i in osoby:
                    i = i.split(":")
                    #zostaja puste
                    try:
                        osobory_dict.update({int(i[0]): Osoba(int(i[0]), i[1], int(i[2]))})
                    except ValueError:
                        pass
                #id_osoba, id_sprzet
                for i in wypozczenia:
                    i = i.split(":")
                    #zostaja puste
                    try:
                        wypozyczeniory.append(Wypozyczenie(int(i[0]), int(i[1])))
                    except ValueError:
                        pass
            print("Odczytano")
            run_along = True
            pass
        if option == 3:
            for i in wypozyczeniory:
                #do zmiennych, bo szybsze niz wyciaganie wartosci z dict, co chwile
                osoba = osobory_dict[i.id_osoba]
                sprzet = sprzeciory_dict[i.id_sprzet]
                if ((osoba.wiek < 25) and (sprzet.type == "hulajnoga")):
                    #tylko wyswietl, wiec szanujmy ram
                    print(osoba.nazwisko, osoba.wiek)
                else:
                    pass
            run_along = True
            pass
        if option == 4:
            ile = 0
            for i in wypozyczeniory:
                sprzet = sprzeciory_dict[i.id_sprzet]
                if sprzet.type == "rower":
                    ile += 1
            print("Wypozyczono %s rowerow." % ile)
            run_along = True
        if option == 5:
            print("papa")
            run_along = True
            running = False
        if not(run_along):
            print("Nieprawidlowa komenda")