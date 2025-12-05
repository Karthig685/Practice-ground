def parse_hours(timestr):
    # Convert "HH:MM" to decimal hours
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

    # Handle rounding overflow (e.g., 7:59 + 0:01 → 8:60 → 9:00)
    if minutes == 60:
        hours += 1
        minutes = 0

    return f"{hours:02d}:{minutes:02d}"


def main():
    days = int(input("Enter number of days: "))
    total = 0.0

    for i in range(1, days + 1):
        t = input(f"Enter working time for day {i} (HH:MM): ")
        total += parse_hours(t)

    avg = total / days

    print("\n--- RESULTS ---")
    #print("Total working hours (decimal):", total)
    print("Total working hours (HH:MM):", format_hours(total))
    #print("Average working hours (decimal):", avg)
    print("Average working hours (HH:MM):", format_hours(avg))


if __name__ == "__main__":
    main()
