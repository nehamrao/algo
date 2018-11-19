class CountInversion:
    def countInversions(self, nums):
        # Base Case
        if len(nums) == 1:
            return nums, 0

        # Recursion
        left_nums, left_inv = self.countInversions(nums[:len(nums)//2])
        right_nums, right_inv = self.countInversions(nums[len(nums)//2:])
        sorted, split_inv = self._countSplitInversions(left_nums, right_nums)
        return sorted, (left_inv + right_inv + split_inv)

    def _countSplitInversions(self, a, b):
        i = j = inv = 0
        c = []
        while i < len(a) and j < len(b):
            if b[j] < a[i]:
                c.append(b[j])
                inv += len(a[i:])
                j += 1
            elif b[j] >= a[i]:
                c.append(a[i])
                i += 1

        c += a[i:]
        c += b[j:]
        return c, inv


def main():
    # Read from input file
    with open("./inversion.txt") as f:
        content = f.readlines()
    # Remove newline chars via strip()
    numbers = [int(x.strip()) for x in content]
    output, count = CountInversion().countInversions(numbers)
    print("Number of inversions {}".format(count))


if __name__ == '__main__':
    main()
