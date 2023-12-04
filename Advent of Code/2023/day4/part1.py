import sys, re

ans = 0
for card in sys.stdin:
    card = re.sub(r"Card\s+\d+:\s+", "", card)
    winning, have = [{int(card) for card in cards.split()} for cards in card.split(" | ")]
    won = winning & have
    if won:
        ans += 1 << len(won) - 1
print(ans)