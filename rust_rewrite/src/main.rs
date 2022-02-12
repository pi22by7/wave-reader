use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

fn read_file(mut file_name: String) -> Vec<u8> {
    file_name = file_name.replace("/", "");
    if file_name.is_empty() {
        file_name = String::from("index.html");
    }

    let path = Path::new(&file_name);
    if !path.exists() {
        return String::from("Not Found!").into();
    }
    let mut file_content = Vec::new();
    let mut file = File::open(&file_name).expect("Unable to open file");
    file.read_to_end(&mut file_content).expect("Unable to read");
    file_content
}

fn main() {
    let s = String::from("H:\\codeshid\\wave file reader\\tests\\test.wav");
    println!("read {:?}", read_file(s));
}