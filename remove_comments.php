<?php
// Function to remove comments from a C program
function remove_comments($input_file, $output_file) {
    // Read the input file
    $input_contents = file_get_contents($input_file);

    // Remove single-line comments
    $input_contents = preg_replace('/\/\/(.*)/', '', $input_contents);

    // Remove multi-line comments and detect invalid comment structures
    $input_contents = preg_replace_callback(
        '/\/\*(.*?)\*\//s',
        function ($match) {
            // Check if the matched comment contains nested comments
            if (preg_match('/\/\*(.*?)\*\//s', $match[1])) {
                // Print error message for nested comments
                echo "Error: Nested comments found!\n";
                return '';
            } else {
                // Remove the valid multi-line comment
                return '';
            }
        },
        $input_contents
    );

    // Write the modified content to the output file
    file_put_contents($output_file, $input_contents);
}

// Specify input and output file paths
$input_file = 'cycle.c';
$output_file = 'output.c';

// Remove comments from the input C program
remove_comments($input_file, $output_file);

echo "Comments removed successfully!";
?>
