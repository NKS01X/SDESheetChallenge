function checkTheInt(x: string): number {
    switch (x) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
    }
}


function romanToInt(s: string): number {
    let sum: number = 0;
    for (let i = 0; i < s.length; i++) {
        const current = checkTheInt(s[i]);
        const next = checkTheInt(s[i + 1]);
        
        if (next > current) {
            sum += (next - current);
            i++;
        } else {
            sum += current;
        }
    }
    return sum;
}

