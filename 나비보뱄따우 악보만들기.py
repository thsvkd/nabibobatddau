import pyperclip
import time

# default_text = "{,,},"
# sheet = "//1\n"


def main():

    sheet = "//1\n"
    bar_num_index = 1
    bar = 0
    bar_num = 0
    mod = 0                 # mod 0 = 입력모드   mod 1 = 기존 악보 변환 모드
    flag = -1
    high_line = []
    low_line = []

    if mod == 0:
        while True:
            note = input()
            if note == "0 0 0":
                sheet += "{0,0,0}"
                print("sheet fin\n")
                break
            else:
                note = note.split()

                if note[0] == "n1":
                    bar += 64
                elif note[0] == "n2":
                    bar += 32
                elif note[0] == "n4":
                    bar += 16
                elif note[0] == "n8":
                    bar += 8
                elif note[0] == "n16":
                    bar += 4
                elif note[0] == "n32":
                    bar += 2
                elif note[0] == "n64":
                    bar += 1
                elif note[0] == "n12":
                    bar += 64+32
                elif note[0] == "n24":
                    bar += 32+16
                elif note[0] == "n48":
                    bar += 16+8
                elif note[0] == "n86":
                    bar += 8 + 4
                else:
                    print("음계를 잘못 입력하신듯??\n{}".format(bar))
                    continue

                print("{}\n".format(bar))

                if len(note) == 3:
                    note[1] = "p_" + note[1].upper()
                    note[2] = "p_" + note[2].upper()
                    sheet += "{" + \
                        "{0},{1},{2}".format(
                            note[0], note[1], note[2]) + "},\n"
                elif len(note) == 2:
                    note[1] = "p_" + note[1].upper()
                    sheet += "{" + \
                        "{0},{1},0".format(note[0], note[1]) + "},\n"
                else:
                    sheet += "{" + \
                        "{0},0,0".format(note[0]) + "},\n"

                if bar == 64:
                    bar = 0
                    bar_num += 1
                    sheet += "\n"

                if bar_num == 4:
                    bar_num = 0
                    sheet += "\n\n//" + "{}".format(bar_num_index)
                    bar_num_index += 1
    elif mod == 1:
        f = open("C:/Users/thsxo/OneDrive/문서/Visual Studio Code/나비보뱃따우 악보.txt", 'r')
        while True:
            tmp = f.readline()
            if tmp == "//high\n":
                flag = 0
                continue
            elif tmp == "//low\n":
                flag = 1
                continue

            if flag == 0:
                high_line.append(tmp)
            elif flag == 1:
                low_line.append(tmp)

            if not tmp:
                break

        # print(high_line)
        # print(low_line)

        high_line_str = ""
        low_line_str = ""

        for i in high_line:
            if i[0] == '{':
                tmp = i[1:len(i) - 4].split(',')
                if len(tmp) > 3:
                    high_line_str += "{" + \
                        "{0},{1}".format(tmp[0], tmp[1]) + "},\n"

        for i in low_line:
            if len(i) > 0 and i[0] == '{':
                tmp = i[1:len(i) - 4].split(',')
                if len(tmp) > 3:
                    low_line_str += "{" + \
                        "{0},{1}".format(tmp[0], tmp[1]) + "},\n"
            else:
                low_line_str += i

        print(high_line_str)
        print(low_line_str)
        pyperclip.copy(low_line_str)


if __name__ == "__main__":
    main()
