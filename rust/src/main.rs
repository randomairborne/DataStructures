mod linked_list;

pub use linked_list::LinkedList;

fn main() {
    let mut list = LinkedList::new();
    eprintln!("starting");
    for x in 0..=100_000 {
        list.push(x);
    }
    eprintln!("pushed everything");
    let data = *list.get(100_000).unwrap();
    assert_eq!(data, 100_000);
    println!("{data}");
}
