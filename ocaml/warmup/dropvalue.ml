(* drop a given value from a list of elements *)

let rec dropval lst v = 
  match lst with
  | [] -> []
  | h::t -> 
    let new_lst = dropval t v in
    if (h = v) then new_lst else h::new_lst;;

(* helper function: to print a list *)
let print_lst lst = 
  print_string "[ ";
  List.iter (fun x -> Printf.printf "%d " x) lst;
  print_string "]\n";;

(* test program *)
let () = 
  let l1 = [1;2;3;4;5;6] in 
  begin
    print_string "the original list: \n";
    print_lst l1;
    print_string "\nafter dropping 2 from the list: \n";
    print_lst (dropval l1 2)
  end
