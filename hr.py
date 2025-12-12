def parse_hours(timestr):
    # Convert "HH.MM" to decimal hours 
    try:
        parts = timestr.split('.')
        hours = int(parts[0])
        minutes = int(parts[1])
        return hours + minutes / 60.0
    except:
        print("Invalid time format. Use HH.MM")
        return 0


def format_hours(decimal_hours):
    # Convert decimal hours back to "HH:MM" 
    hours = int(decimal_hours)
    minutes = int(round((decimal_hours - hours) * 60))

    if minutes == 60:  # Fixoverflow
        hours += 1
        minutes = 0

    return f"{hours:02d}:{minutes:02d}"


def update_existing_avg():
    print("\n--- UPDATE EXISTING AVERAGE MODE ---")
    days = int(input("Enter number of days already worked (e.g., 4): "))
    avg = parse_hours(input("Enter existing average (HH.MM), e.g., 8.30: "))

    # total hours already done
    total_prev = days * avg

    # new day's entry
    new_day = parse_hours(input("Enter today's working hours (HH.MM): "))

    total_new = total_prev + new_day
    new_avg = total_new / (days + 1)

    print("\n--- UPDATED RESULTS ---")
    print("Total working hours (HH:MM):", format_hours(total_new))
    print("New average (HH:MM):", format_hours(new_avg))


def normal_mode():
    print("\n--- NORMAL MODE ---")
    days = int(input("Enter number of days: "))
    total = 0.0

    for i in range(1, days + 1):
        t = input(f"Enter working time for day {i} (HH.MM): ")
        total += parse_hours(t)

    avg = total / days

    print("\n--- RESULTS ---")
    print("Total working hours (HH:MM):", format_hours(total))
    print("Average working hours (HH:MM):", format_hours(avg))


def main():
    print("Choose Mode:")
    print("1. Normal (enter all days)")
    print("2. Update existing average (e.g., you already worked 4 days avg 8.30)")
    choice = input("Enter choice (1/2): ")

    if choice == "2":
        update_existing_avg()
    else:
        normal_mode()


if __name__ == "__main__":
    main()
