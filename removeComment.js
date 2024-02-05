const fs = require("fs");

// Function to remove comments from C code and handle specific patterns
function processComments(code) {
  // Replace valid single-line comments
  let uncommentedCode = code.replace(/\/\/.*(?=\n)/g, "");

  // Remove valid multi-line comments
  uncommentedCode = uncommentedCode.replace(/\/\*[\s\S]*?\*\//g, "");

  // Specific pattern handling
  uncommentedCode = uncommentedCode.replace(/\/\*.*$/gm, "");

  // Find dangling comment closers '*/'
  // Remove '*/' that appear without a matching '/*'
  uncommentedCode = uncommentedCode.replace(/^\s*\*\/.*$/gm, "");

  return uncommentedCode;
}

// Process File Path
const filePath = "cycle.c";

// Read the input C program file
fs.readFile(filePath, "utf8", (err, data) => {
  if (err) {
    console.error(err);
    return;
  }

  try {
    const result = processComments(data);
    console.log("Processed code:", result);

    fs.writeFile("output.c", result, (err) => {
      if (err) {
        console.error(err);
        return;
      }
      console.log("Comments processed successfully and saved to output.c");
    });
  } catch (error) {
    console.error(error.message);
  }
});
