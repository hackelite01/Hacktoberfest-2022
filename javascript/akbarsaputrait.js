// Contributor  : akbarsaputrait
// Date         : 05 October 2022
// City         : Malang, Indonesia

/**
 * Generates a random id
 *
 * @param length
 */
function randomId(length = 10) {
  const chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  let id = "";

  for (let i = 0; i < length; i++) {
    id += chars.charAt(Math.floor(Math.random() * chars.length));
  }

  return id;
}

console.log(randomId());
