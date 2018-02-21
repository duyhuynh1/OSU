# Project 7.b
## Requirements
- Create a Person class
  - Provide getters for name and age

- Create a function called stdDev
  - @param: *people* An array of Person objects
  - @param: *size* The size of the Person array
  - @return: *result* The calculated population age standard deviation

## Population Standard Deviation
(https://www.thoughtco.com/population-standard-deviation-calculation-609522)
Standard deviation is a calculation of the dispersion or variation in a set of numbers. If the standard deviation is a *small* number, it means the data points are close to their average value. If the deviation is *large*, it means the numbers are spread out, further from the mean or average.

There are two types of standard deviation calculations. **Population standard deviation** looks at the square root of the variance of the set of numbers.

It's used to determine a confidence interval for drawing conclusions (such as accepting or rejecting a hypothesis). A slightly more complex calculation is called sample standard deviation. This is a simple example of how to calculate variance and population standard deviation. First, let's review how to calculate the population standard deviation:

$$
\sigma = \sqrt{\sum\frac{(x-\mu)^2}{N}}
$$

Where:
\sigma = population standard deviation
x1,...,xN = the population age data set
\mu = mean age of the population data set
N = size of the population data set

1. Find the mean age of all the People. Store value in \mu
2. Calculate variance by summing each (Person's age - mean age)^2
3. Return the standard deviation by taking the square root of the variance