from datetime import timedelta

def type_guard(q: str, lower: int, upper: int) -> int:
    while True:
        try:
            ans = int(input(q))
            assert lower <= ans <= upper
        except (ValueError, AssertionError):
            print('#\tPlease enter a valid value.')
        else:
            return ans
def main():
    print("#\tHello! How may I be of service?")
    print("\t\tDo you think I'm getting enough sleep?")
    print("#\tWell, of course!")
    print("#\tBut, I need you to answer some questions.")

    print('#\t(1/5)')
    print('#\tWhat hour do you normally go to bed?')
    htb = type_guard("\tI usually go to bed around (0 - 23) >> ", 0, 23)

    print('#\t(2/5)')
    print('#\tWhat minute do you normally go to bed?')
    mtb = type_guard("\tI usually go to bed around (0 - 59) >> ", 0, 59)

    print("#\t(3/5)")
    print("#\tWhat hour do you normally get out of bed?")
    hob = type_guard('\tI usually wake up around (0 - 23) >> ', 0, 23)

    print("#\t(4/5)")
    print("#\tWhat minute do you normally get out of bed?")
    mob = type_guard('\tI usually wake up around (0 - 59) >> ', 0, 59)

    print("#\t(5/5)")
    print("#\tHow old are you again?")
    age = type_guard("\tI'm >> ", 0, 1500)

    t0 = timedelta(hours=htb, minutes=mtb)
    t1 = timedelta(hours=hob, minutes= mob)
    if t1 > t0:
        time_slept = int((t1 - t0).total_seconds()) // 60
    else:
        time_slept = (86400 - int((t0 - t1).total_seconds())) // 60
    
    rec_sleep = ((540,720),(480,600),(420,600),(420,720),(540,720),(600,720),(660,720))
    age_class = age // 10
    if age_class > 6:
        age_class = 6
    sleep_minimal, sleep_max = rec_sleep[age_class]
    
    print(f'#\tFor someone at the age of {age}.')
    print(f'#\tYou should be getting between {sleep_minimal // 60} and {sleep_max // 60} hours')
    print(f'#\tYour sleep duration of {time_slept // 60} hours and {time_slept % 60} minute')
    if time_slept > sleep_max:
        print('#\tis too much!')
    elif time_slept < sleep_minimal:
        print('#\tis too little.')
    else:
        print('#\tis just right.')

if __name__ == '__main__':
    main()