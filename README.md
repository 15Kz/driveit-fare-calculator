# DriveIt 🚗

A beginner C++ console program that simulates a ride-hailing app. You enter the distance of your trip, it computes the fare, and then you pay using one of three payment methods.

## Features

- **Fare computation** based on distance:
  - Up to 2 km: flat ₱50
  - Over 2 km up to 7 km: ₱50 plus ₱10 for every km beyond 2
  - Over 7 km: ₱100 plus ₱15 for every km beyond 7
- **Three payment methods:**
  - **Cash:** enter the amount you hand over. If it's too much, the program gives change. If it's too little, it tells you the remaining balance and asks again.
  - **GCash:** enter the GCash number shown on screen, wait for a randomly generated 4-digit verification code, then enter it and pay.
  - **Credit:** enter a PIN (limited to a few attempts) before paying. Too many wrong tries and the program tells you to contact your bank.
- **Partial payments:** if you pay less than the total, the program keeps asking until the fare is fully paid.

## Concepts Practiced

- Variables and data types (`double`, `int`, `string`)
- Conditionals (`if / else if / else`) and `switch`
- Loops (`do-while`, `for`)
- Random number generation (`<random>`)
- Delays with `<thread>` and `<chrono>`

## How to Run

1. Make sure you have a C++ compiler such as g++ (C++11 or newer).
2. Compile `main.cpp` and run the resulting program in your terminal.
3. Follow the prompts: enter the distance, pick a payment method, and pay.

## Demo Credentials (for testing only)

- GCash number: `09123456789`
- Credit card PIN: `1500`

## Known Limitations

- Negative or non-numeric distance input isn't fully validated yet.
- Payment details are hard-coded for demo purposes. No real payment is processed.

## Author

First-year BSIT student, learning C++ one program at a time.
